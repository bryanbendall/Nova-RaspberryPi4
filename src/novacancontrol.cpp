#include "novacancontrol.h"

#include <QDebug>
#include "bryteccan.h"

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

    system("sudo ip link set can0 up type can bitrate 500000");

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
    connect(m_timer, &QTimer::timeout, this, &NovaCanControl::readFrame);
    m_timer->start(100);
}

#define BT_StartButton 0
#define BT_DriversDoor 1
#define BT_Black9 2
#define BT_DoorSpeed 3
#define BT_PassDoor 4
#define BT_PWindowDownButton 5
#define BT_EngineRunning 6
#define BT_RightTurnSwitch 7
#define BT_BrakeSwitch 8
#define BT_WaterInjPumpTrig 9
#define BT_FuelPump1Trig 10
#define BT_LeftTurnSwitch 11
#define BT_CoolingFan 12
#define BT_Blue19 13
#define BT_NeutralSafety 14
#define BT_Blue31 15
#define BT_StartButtonLight 16
#define BT_PassWindowDir 17
#define BT_Black13 18
#define BT_Black14 19
#define BT_Black15 20
#define BT_DriverWindowDir 21
#define BT_DriverWindowCtrl 22
#define BT_PassWindowCtrl 23
#define BT_Blue13 24
#define BT_PassWindowCS 25
#define BT_DriverWindowCS 26
#define BT_SteeringWheelSwitches 27
#define BT_LightSwitchUp 28
#define BT_IgnitionSwitch 29
#define BT_LightSwitchDown 30
#define BT_FanUp 31
#define BT_ACOn 32
#define BT_FanDown 33
#define BT_PWindowUpButton 34
#define BT_DWindowUpButton 35
#define BT_DWindowDownButton 36
#define BT_BlinkerFlash 37
#define BT_LightState 38

bool toBool(float& value){
    return value > 0.0001f;
}

void NovaCanControl::readFrame()
{
//    qDebug() << "Frames available: " << m_can1->framesAvailable();
    for(int i = 0; i < m_can1->framesAvailable(); i++){
        QCanBusFrame frame = m_can1->readFrame();
        m_rawData[frame.frameId()] = frame;
    }

    for(auto frame : m_rawData){
        PinStatusBroadcast bc(frame);

//        if(bc.moduleAddress != 99)
//            return;

        switch(bc.nodeGroupIndex){
        case BT_IgnitionSwitch:
            m_ignition = toBool(bc.value);
            break;
        case BT_BrakeSwitch:
            m_brakeLights = toBool(bc.value);
            break;
        case BT_LeftTurnSwitch:
            m_leftTurn = toBool(bc.value);
            break;
        case BT_RightTurnSwitch:
            m_rightTurn = toBool(bc.value);
            break;
        case BT_LightState:
            m_parkingLights = bc.value >= 0.5f;
            m_lowBeam = bc.value >= 1.5f && bc.value < 2.5f;
            m_highBeam = bc.value >= 2.5f;
            m_fogLights = bc.value >= 1.5f;
            break;
        case BT_CoolingFan:
            m_coolingFan = toBool(bc.value);
            break;
        case BT_FuelPump1Trig:
            m_gasPump = toBool(bc.value);
            break;
        case BT_WaterInjPumpTrig:
            m_methPump = toBool(bc.value);
            break;
        }
    }

    emit onNovaDataChanged();
}















