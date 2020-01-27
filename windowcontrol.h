#ifndef WINDOWCONTROL_H
#define WINDOWCONTROL_H

#include <QObject>
#include "serialcomm.h"

class WindowControl : public QObject
{
    Q_OBJECT
    SerialComm* m_serial;

public:
    explicit WindowControl(SerialComm* serial, QObject *parent = nullptr);

signals:

public slots:
    void driverDown(bool state);
    void driverUp(bool state);
    void passDown(bool state);
    void passUp(bool state);
};

#endif // WINDOWCONTROL_H
