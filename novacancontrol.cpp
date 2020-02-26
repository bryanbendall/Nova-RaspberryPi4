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

    system("sudo ip link set can1 up type can bitrate 250000");

    if (!QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"))) {
        qDebug() << "SocketCan not available!";
        return;
    }

    QString errorString;
    bool connectionStatus;
    m_can1 = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("can1"), &errorString);
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
}

void NovaCanControl::readFrame()
{
    QCanBusFrame frame = m_can1->readFrame();
}
