#include "windowcontrol.h"
#include "tabcommdefs.h"
#include <QDebug>

WindowControl::WindowControl(SerialComm* serial, QObject *parent) : QObject(parent), m_serial(serial)
{

}

void WindowControl::driverDown(bool state)
{
    m_serial->sendData(TAB_WINDOW_DRIVER_DOWN);
    m_serial->sendData(state);
}

void WindowControl::driverUp(bool state)
{
    m_serial->sendData(TAB_WINDOW_DRIVER_UP);
    m_serial->sendData(state);
}

void WindowControl::passDown(bool state)
{
    m_serial->sendData(TAB_WINDOW_PASS_DOWN);
    m_serial->sendData(state);
}

void WindowControl::passUp(bool state)
{
    m_serial->sendData(TAB_WINDOW_PASS_UP);
    m_serial->sendData(state);
}
