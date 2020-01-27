#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

#include <QObject>
#include "serialcomm.h"

class LightControl : public QObject
{
    Q_OBJECT

    SerialComm* m_serial;
    bool m_running = false;
    bool m_parking = false;
    bool m_lowBeam = false;
    bool m_highBeam = false;
    bool m_interior = false;

    Q_PROPERTY(bool running MEMBER m_running NOTIFY onRunningChanged)
    Q_PROPERTY(bool parking MEMBER m_parking NOTIFY onParkingChanged)
    Q_PROPERTY(bool lowBeam MEMBER m_lowBeam NOTIFY onLowBeamChanged)
    Q_PROPERTY(bool highBeam MEMBER m_highBeam NOTIFY onHighBeamChanged)
    Q_PROPERTY(bool interior MEMBER m_interior NOTIFY onInteriorChanged)

public:
    explicit LightControl(SerialComm* serial, QObject *parent = nullptr);



signals:
    void onRunningChanged();
    void onParkingChanged();
    void onLowBeamChanged();
    void onHighBeamChanged();
    void onInteriorChanged();

public slots:
    void setOff();
    void setRunning();
    void setParking();
    void setLowBeam();
    void setHighBeam();
    void setInterior();

};

#endif // LIGHTCONTROL_H
