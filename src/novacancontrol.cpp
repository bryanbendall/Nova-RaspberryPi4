#include "novacancontrol.h"

#include <QDebug>

NovaCanControl::NovaCanControl(QObject *parent) : QObject(parent)
{
#ifdef NOVA
    QMetaObject::invokeMethod(this, &NovaCanControl::connectToCan, Qt::QueuedConnection);
#endif
}

NovaCanControl::~NovaCanControl()
{
    m_timer->stop();
    delete m_timer;
}

void NovaCanControl::connectToCan()
{

    system("sudo ip link set can0 up type can bitrate 20000");

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
        connect(m_can1, &QCanBusDevice::framesReceived, this, &NovaCanControl::readFrame);

        connectionStatus = m_can1->connectDevice();
    }

    if(!connectionStatus){
        qDebug() << "Connection Failed!";
        return;
    }

    qDebug() << "can0 connect successful";

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &NovaCanControl::onNovaDataChanged);
    m_timer->start(20);

    sendUnlock();
}

void NovaCanControl::readFrame()
{
    QCanBusFrame frame = m_can1->readFrame();
    bool state = frame.payload().at(3);

    switch(frame.frameId()){
        case ID_INTERIOR_MODULE:
            switch(frame.payload().at(2)){
                case PM_PIN_4_ADDR: m_ignition = state; break;
            }
            break;
        case ID_FRONT_MODULE_1:
            switch(frame.payload().at(2)){
                case PM_PIN_10_ADDR: m_coolingFan = state; break;
            }
            break;
        case ID_FUEL_PUMP_MODULE:
            switch(frame.payload().at(2)){
                case PM_PIN_1_ADDR: m_gasPump = state; break;
                case PM_PIN_2_ADDR: m_methPump = state; break;
            }
            break;
        case ID_REAR_MODULE:
            switch(frame.payload().at(2)){
                case PM_PIN_11_ADDR: m_reverseLights = state; break;
                case PM_PIN_12_ADDR: (unsigned char)frame.payload().at(3) > 250 ? m_brakeLights = true : m_brakeLights = false; break;
            }
            break;
        case ID_FRONT_LIGHT_MODULE:
            switch(frame.payload().at(2)){
                case PM_PIN_10_ADDR: m_lowBeam = state; break;
                case PM_PIN_11_ADDR: m_highBeam = state; break;
                case PM_PIN_2_ADDR: m_parkingLights = state; break;
                case PM_PIN_1_ADDR: m_fogLights = state; break;
                case PM_PIN_13_ADDR: m_rightTurn = state; break;
                case PM_PIN_3_ADDR: m_leftTurn = state; break;
            }
            break;
    }

}

void NovaCanControl::sendUnlock()
{
    QCanBusFrame unlockFrame(0xFA, QByteArray::fromHex("F92300"));
    m_can1->writeFrame(unlockFrame);
}

















