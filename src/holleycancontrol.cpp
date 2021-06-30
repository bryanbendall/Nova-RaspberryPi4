#include "holleycancontrol.h"

#include <QDebug>
#include <QTime>

HolleyCanControl::HolleyCanControl(QObject *parent)
    : QObject(parent)
{
#if defined(CAMARO) || defined(NOVA)
    QMetaObject::invokeMethod(this, &HolleyCanControl::connectToCan, Qt::QueuedConnection);
#endif
}

HolleyCanControl::~HolleyCanControl()
{
    m_timer->stop();
    delete m_timer;
}

void HolleyCanControl::connectToCan()
{
    system("sudo ip link set can1 up type can bitrate 1000000");

    if (!QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"))) {
        qDebug() << "SocketCan not available!";
        return;
    }

    QString errorString;
    bool connectionStatus;
    m_can = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("can1"), &errorString);
    if (!m_can) {
        // Error handling goes here
        qDebug() << "Creating Device Error: " << errorString;
        return;
    } else {

        setupFilters();

        connect(m_can, &QCanBusDevice::errorOccurred, [=](){qDebug() << "QCanBusDevice::errorOccurred - " << m_can->errorString();});
        connect(m_can, &QCanBusDevice::stateChanged, [=](){qDebug() << "QCanBusDevice::stateChanged - " << m_can->state();});
        connect(m_can, &QCanBusDevice::framesReceived, this, &HolleyCanControl::readFrame);

        connectionStatus = m_can->connectDevice();
    }

    if(!connectionStatus){
        qDebug() << "Connection Failed!";
        return;
    }

    m_setupDone = true;
    qDebug() << "can1 connect successful";

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &HolleyCanControl::onHolleyDataChanged);
    m_timer->start(20);

}

void HolleyCanControl::readFrame()
{
    for(int i = 0; i < m_can->framesAvailable(); i++){
        //qDebug() << "Frames available: " << m_can0->framesAvailable();
        QCanBusFrame frame = m_can->readFrame();
        //qDebug() << "Recieved Frame: " << frame.frameId();


        /////////////////////////////////////////////////////////////////////
        // Bail if its not from the ecu

        unsigned char sourceId = (frame.frameId() >> 11) & 0x07;

        if(sourceId != 0x02){
            //qDebug() << "Bailing because not ecu";
            return;
        }
        /////////////////////////////////////////////////////////////////////

        unsigned int index = (frame.frameId() & 0x1FFC000) >> 14;
        m_data[index] = getFloat(frame);

        if(index == 220){
            // Odometer calculation
            static double speed1 = 0.0;
            static double speed2 = 0.0;
            static QTime time;
            static bool setupDone = false;
            if(!setupDone){
                time.start();
                setupDone = true;
            }

            double elapsedHours = (double)time.restart() * 2.7777777777778E-7;
            m_odometer += ((speed1 + speed2) / 2.0) * elapsedHours;

            speed2 = speed1;
            speed1 = (double)getFloat(frame);

        }

    }

}

void HolleyCanControl::setupFilters()
{
    QCanBusDevice::Filter filter;
    QList<QCanBusDevice::Filter> filterList;

    filter.frameIdMask = 0x1FFC000;
    filter.format = QCanBusDevice::Filter::MatchExtendedFormat;
    filter.type = QCanBusFrame::DataFrame;

    for(auto f : m_filterId){
        filter.frameId = ((unsigned long)f << 14);
        filterList.append(filter);
    }

    // apply filter
    m_can->setConfigurationParameter(QCanBusDevice::RawFilterKey, QVariant::fromValue(filterList));
}

float HolleyCanControl::getFloat(QCanBusFrame &frame)
{
    unsigned long temp = ((unsigned long)frame.payload().at(0) << 24) |
            ((unsigned long)frame.payload().at(1) << 16) |
            ((unsigned long)frame.payload().at(2) << 8) |
            (unsigned long)frame.payload().at(3);

    float f = *((float*)&temp);
    return f;
}

void HolleyCanControl::registerFilter(unsigned int filter)
{
    if(m_setupDone)
        return;
    if(m_filterId.contains(filter))
        return;
    m_filterId.push_back(filter);
}
