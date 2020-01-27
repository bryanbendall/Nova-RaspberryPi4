#include "qtcancontrol.h"
#include <QDebug>

QtCanControl::QtCanControl(QObject *parent) : QObject(parent)
{

}

void QtCanControl::connectToCan()
{
    system("sudo ip link set can0 up type can bitrate 125000");

    if (!QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"))) {
        qDebug() << "SocketCan not available!";
        return;
    }

    QString errorString;
    bool connectionStatus;
    m_can0 = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("can0"), &errorString);
    if (!m_can0) {
        // Error handling goes here
        qDebug() << "Creating Device Error: " << errorString;
        return;
    } else {

        connect(m_can0, &QCanBusDevice::errorOccurred, [=](){qDebug() << "QCanBusDevice::errorOccurred - " << m_can0->errorString();});
        connect(m_can0, &QCanBusDevice::stateChanged, [=](){qDebug() << "QCanBusDevice::stateChanged - " << m_can0->state();});
        connect(m_can0, &QCanBusDevice::framesReceived, this, &QtCanControl::readFame);

        connectionStatus = m_can0->connectDevice();
    }

    if(!connectionStatus){
        qDebug() << "Connection Failed!";
        return;
    }

}

void QtCanControl::readFame()
{
    qDebug() << "Frames available: " << m_can0->framesAvailable();
    QCanBusFrame frame = m_can0->readFrame();
    qDebug() << "Recieved Frame: " << frame.frameId();
}
