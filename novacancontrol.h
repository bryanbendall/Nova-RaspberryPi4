#ifndef NOVACANCONTROL_H
#define NOVACANCONTROL_H

#include <QObject>
#include <QCanBus>
#include <QTimer>

//Module IDs
#define ID_ALL_MODULES				0x0000
#define ID_FRONT_LIGHT_MODULE		0x00FE
#define ID_FUEL_PUMP_MODULE			0x00FD
#define ID_REAR_MODULE				0x00FC
#define ID_INTERIOR_MODULE			0x00FB
#define ID_INPUT_MODULE				0x00FA
#define ID_LOCK_MODULE				0x00F9
#define ID_FRONT_MODULE_1			0x00F8
//Power module pin addresses
#define PM_PIN_1_ADDR				0x01
#define PM_PIN_2_ADDR				0x02
#define PM_PIN_3_ADDR				0x03
#define PM_PIN_4_ADDR				0x04
#define PM_PIN_10_ADDR				0x05
#define PM_PIN_11_ADDR				0x06
#define PM_PIN_12_ADDR				0x07
#define PM_PIN_13_ADDR				0x08

class NovaCanControl : public QObject
{
    Q_OBJECT

    QCanBusDevice* m_can1;
    QTimer* m_timer;

    bool m_ignition = false;
    //bool m_eBrake = false;
    bool m_brakeLights =false;
    bool m_reverseLights = false;
    bool m_leftTurn = false;
    bool m_rightTurn = false;
    bool m_parkingLights = false;
    bool m_lowBeam = false;
    bool m_highBeam = false;
    bool m_fogLights = false;
    bool m_coolingFan = false;
    bool m_gasPump = false;
    bool m_methPump = false;

    Q_PROPERTY(bool Ignition        MEMBER m_ignition         NOTIFY onNovaDataChanged)
    //Q_PROPERTY(bool EBrake          MEMBER m_eBrake           NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool BrakeLights     MEMBER m_brakeLights      NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool ReverseLights   MEMBER m_reverseLights    NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool LeftTurn        MEMBER m_leftTurn         NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool RightTurn       MEMBER m_rightTurn        NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool ParkingLights   MEMBER m_parkingLights    NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool LowBeam         MEMBER m_lowBeam          NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool HighBeam        MEMBER m_highBeam         NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool FogLights       MEMBER m_fogLights        NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool CoolingFan      MEMBER m_coolingFan       NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool GasPump         MEMBER m_gasPump          NOTIFY onNovaDataChanged)
    Q_PROPERTY(bool MethPump        MEMBER m_methPump         NOTIFY onNovaDataChanged)

public:
    explicit NovaCanControl(QObject *parent = nullptr);
    ~NovaCanControl();

signals:
    void onNovaDataChanged();

public slots:
    void connectToCan();
    void readFrame();

    void sendUnlock();

};

#endif // NOVACANCONTROL_H
