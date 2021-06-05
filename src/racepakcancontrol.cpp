#include "racepakcancontrol.h"

#include <QDebug>

RacepakCanControl::RacepakCanControl(QObject *parent) : QObject(parent)
{
#ifdef CAMARO
    QMetaObject::invokeMethod(this, &RacepakCanControl::connectToCan, Qt::QueuedConnection);
#endif
}

RacepakCanControl::~RacepakCanControl()
{
    m_timer->stop();
    delete m_timer;
}

void RacepakCanControl::connectToCan()
{

    system("sudo ip link set can1 up type can bitrate 250000");

    if (!QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"))) {
        qDebug() << "SocketCan not available!";
        return;
    }

    QString errorString;
    bool connectionStatus;
    m_can1 = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("can1"), &errorString);
    if (!m_can1) {
        // Error handling goes here
        qDebug() << "Creating Device Error: " << errorString;
        return;
    } else {

        connect(m_can1, &QCanBusDevice::errorOccurred, [=](){qDebug() << "QCanBusDevice::errorOccurred - " << m_can1->errorString();});
        connect(m_can1, &QCanBusDevice::stateChanged, [=](){qDebug() << "QCanBusDevice::stateChanged - " << m_can1->state();});
        connect(m_can1, &QCanBusDevice::framesReceived, this, &RacepakCanControl::readFrame);

        connectionStatus = m_can1->connectDevice();
    }

    if(!connectionStatus){
        qDebug() << "Connection Failed!";
        return;
    }

    qDebug() << "can0 connect successful";

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &RacepakCanControl::onRacepakDataChanged);
    m_timer->start(20);
}

void RacepakCanControl::readFrame()
{
    QCanBusFrame frame = m_can1->readFrame();

    switch (frame.frameId()) {
    case 0x190:
        decodeSwitches(frame);
        break;
    default:
        decodeOutput(frame);
        break;
    }

}

void RacepakCanControl::decodeSwitches(QCanBusFrame &frame)
{
    short data = frame.payload().at(2) & (frame.payload().at(3) << 8);

    for(int i = 0; i < 12; i++){
        m_inputStatus[i] = data & 1;
        data = data >> 1;
    }
}

void RacepakCanControl::decodeOutput(QCanBusFrame &frame)
{
    unsigned int i = frame.frameId() - 0x1b0;
    if(i > 29)
        return;

    m_outputAmps[i] = (float)(frame.payload().at(2) & (frame.payload().at(3) << 8)) / 100.0f;
    m_outputVolts[i] = (float)(frame.payload().at(5) & (frame.payload().at(6) << 8)) / 100.0f;
    m_outputStatus[i] = frame.payload().at(7);
}



















