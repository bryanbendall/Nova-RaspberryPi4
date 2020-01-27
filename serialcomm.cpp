#include "serialcomm.h"
#include "wiringSerial.h"
#include <QTimer>
#include <QDebug>

SerialComm::SerialComm(QObject *parent) : QObject(parent)
{
#ifdef RASPPI
    m_fd = serialOpen ("/dev/ttyS0", 9600);
    QTimer::singleShot(0, this, SLOT(checkSerialData()));
#endif
}

void SerialComm::sendData(unsigned char data)
{
#ifdef RASPPI
    serialPutchar(m_fd, data);
#endif
}

void SerialComm::checkSerialData()
{
#ifdef RASPPI
    if(serialDataAvail(m_fd) > 0){
        int c = serialGetchar(m_fd);
        emit dataAvailable(c);
    }

    QTimer::singleShot(100, this, SLOT(checkSerialData()));
#endif
}
