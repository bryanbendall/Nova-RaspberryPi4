#include "racepakcancontrol.h"

#include <QDebug>
#include <QtEndian>

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

    system("sudo ip link set can0 up type can bitrate 250000");

    if (!QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"))) {
        qDebug() << "SocketCan not available!";
        return;
    }

    QString errorString;
    bool connectionStatus;
    m_can1 = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("can0"), &errorString);
    if (!m_can1) {
        // Error handling goes here
        qDebug() << "Creating Device Error: " << errorString;
        return;
    } else {

        connect(m_can1, &QCanBusDevice::errorOccurred, [=](){qDebug() << "QCanBusDevice::errorOccurred - " << m_can1->errorString();});
        connect(m_can1, &QCanBusDevice::stateChanged, [=](){qDebug() << "QCanBusDevice::stateChanged - " << m_can1->state();});

        connectionStatus = m_can1->connectDevice();
    }

    if(!connectionStatus){
        qDebug() << "Connection Failed!";
        return;
    }

    qDebug() << "can0 connect successful";

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &RacepakCanControl::readFrame);
    m_timer->start(100);
}

void RacepakCanControl::readFrame()
{
    //    qDebug() << "Frames available: " << m_can1->framesAvailable();
    for(int i = 0; i < m_can1->framesAvailable(); i++){
        QCanBusFrame frame = m_can1->readFrame();
        m_rawData[frame.frameId()] = frame;
    }

    for(auto frame : m_rawData){

        switch (frame.frameId()) {
        case 0x190:
            decodeInputs(frame);
            break;
        case 0x194:
            decodeSwitchModule(frame);
            break;
        default:
            decodeOutput(frame);
            break;
        }
    }

    emit onRacepakDataChanged();
}

void RacepakCanControl::decodeInputs(QCanBusFrame &frame)
{
    //unsigned short data = frame.payload().at(2) & (frame.payload().at(3) << 8);

    quint16 data = qFromBigEndian<quint16>(frame.payload().data() + 2);

    for(int i = 0; i < 12; i++){
        m_inputStatus[i] = data & 0x01;
        data = data >> 1;
    }

}

void RacepakCanControl::decodeSwitchModule(QCanBusFrame &frame)
{
    //unsigned short data = frame.payload().at(2) & (frame.payload().at(3) << 8);

    quint16 data = qFromBigEndian<quint16>(frame.payload().data() + 2);

    for(int i = 0; i < 16; i++){
        m_inputSwitchModule[i] = data & 0x01;
        data = data >> 1;
    }
}

void RacepakCanControl::decodeOutput(QCanBusFrame &frame)
{
    //qDebug() << "Racepak output ";
    unsigned int i = frame.frameId() - 0x1b0;
    if(i > 29)
        return;
/*
    m_outputAmps[i] = (float)(((int)frame.payload().at(2)) | ((int)frame.payload().at(3) << 8)) / 100.0f;
    m_outputVolts[i] = (float)(((int)frame.payload().at(5)) | ((int)frame.payload().at(6) << 8)) / 100.0f;
    m_outputStatus[i] = frame.payload().at(7);
*/
    m_outputAmps[i] = static_cast<float>(qFromBigEndian<quint16>(frame.payload().data() + 2)) / 100.0f;
    m_outputVolts[i] = static_cast<float>(qFromBigEndian<quint16>(frame.payload().data() + 5)) / 100.0f;
    m_outputStatus[i] = frame.payload()[7];
}



















