#include "lightcontrol.h"
#include "tabcommdefs.h"
#include <QDebug>

LightControl::LightControl(SerialComm* serial, QObject *parent) : QObject(parent), m_serial(serial)
{

}

void LightControl::setOff()
{
    m_serial->sendData(TAB_LIGHT_OFF);
    m_serial->sendData(OFF);
}

void LightControl::setRunning()
{
    m_serial->sendData(TAB_LIGHT_RUNNING);
    m_serial->sendData(!m_running);
}

void LightControl::setParking()
{
    m_serial->sendData(TAB_LIGHT_PARKING);
    m_serial->sendData(!m_parking);
}

void LightControl::setLowBeam()
{
    m_serial->sendData(TAB_LIGHT_LOW_BEAM);
    m_serial->sendData(!m_lowBeam);
}

void LightControl::setHighBeam()
{
    m_serial->sendData(TAB_LIGHT_HIGH_BEAM);
    m_serial->sendData(!m_highBeam);
}

void LightControl::setInterior()
{
    m_serial->sendData(TAB_LIGHT_INTERIOR);
    m_serial->sendData(!m_interior ? 255 : 0);
}
