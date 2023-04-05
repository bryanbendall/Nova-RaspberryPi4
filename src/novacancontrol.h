#ifndef NOVACANCONTROL_H
#define NOVACANCONTROL_H

#include <QObject>
#include <QCanBus>
#include <QTimer>
#include <QMap>

class NovaCanControl : public QObject
{
    Q_OBJECT

    QCanBusDevice* m_can1;
    QTimer* m_timer;
    QMap<quint32, QCanBusFrame> m_rawData;

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

};

#endif // NOVACANCONTROL_H
