#include "holleycancontrol.h"

#include <QDebug>
#include <QTimer>

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
    //system("sudo ip link set can0 up type can bitrate 1000000");

    if (!QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"))) {
        qDebug() << "SocketCan not available!";
        return;
    }

    QString errorString;
    bool connectionStatus;
    m_can0 = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("can0"), &errorString);
    if (!m_can0) {
        // Error handling goes here
        qDebug() << "Creating Device Error: " << errorString;
        return;
    } else {

        setupFilters();

        connect(m_can0, &QCanBusDevice::errorOccurred, [=](){qDebug() << "QCanBusDevice::errorOccurred - " << m_can0->errorString();});
        connect(m_can0, &QCanBusDevice::stateChanged, [=](){qDebug() << "QCanBusDevice::stateChanged - " << m_can0->state();});
        connect(m_can0, &QCanBusDevice::framesReceived, this, &HolleyCanControl::readFrame);

        connectionStatus = m_can0->connectDevice();
    }

    if(!connectionStatus){
        qDebug() << "Connection Failed!";
        return;
    }

    m_setupDone = true;
    qDebug() << "can0 connect successful";

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &HolleyCanControl::onHolleyDataChanged);
    m_timer->start(20);

}

void HolleyCanControl::readFrame()
{
    for(int i = 0; i < m_can0->framesAvailable(); i++){
        //qDebug() << "Frames available: " << m_can0->framesAvailable();
        QCanBusFrame frame = m_can0->readFrame();
        //qDebug() << "Recieved Frame: " << frame.frameId();

        unsigned int index = (frame.frameId() & 0x1FFC000) >> 14;
        m_data[index] = getFloat(frame);
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
    m_can0->setConfigurationParameter(QCanBusDevice::RawFilterKey, QVariant::fromValue(filterList));
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
    qDebug() << "register filter: " << filter;
}

