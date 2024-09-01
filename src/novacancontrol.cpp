#include "novacancontrol.h"

#include <QDebug>
#include "bryteccan.h"

NovaCanControl* NovaCanControl::s_instance = nullptr;

NovaCanControl::NovaCanControl(QObject *parent) : QObject(parent)
{
    s_instance = this;
#ifdef NOVA
//    QMetaObject::invokeMethod(this, &NovaCanControl::connectToCan, Qt::QueuedConnection);
    QMetaObject::invokeMethod(this, &NovaCanControl::initBrytec, Qt::QueuedConnection);
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

void NovaCanControl::initBrytec()
{
    qDebug() << "Init brytec";
    Brytec::EBrytecApp::initalize();

    if (Brytec::EBrytecApp::isDeserializeOk())
        qDebug() << "Deserialize Ok\n";
    else
        qDebug() << "Deserialize FAIL\n";

    m_brytecTimer = new QTimer(this);
    connect(m_brytecTimer, &QTimer::timeout, [](){ Brytec::EBrytecApp::processCanCommands(); });
    connect(m_brytecTimer, &QTimer::timeout, [](){ Brytec::EBrytecApp::update(10.0f); });
    m_brytecTimer->start(10);
}

void NovaCanControl::readFrame()
{
//    qDebug() << "Frames available: " << m_can1->framesAvailable();
    for(int i = 0; i < m_can1->framesAvailable(); i++){
        QCanBusFrame frame = m_can1->readFrame();
//        m_rawData[frame.frameId()] = frame;
        Brytec::CanFrame brytecFrame;
        brytecFrame.id = frame.frameId();
        brytecFrame.type = frame.hasExtendedFrameFormat() ? Brytec::CanFrameType::Ext : Brytec::CanFrameType::Std;
        brytecFrame.dlc = frame.payload().size();
        memcpy(brytecFrame.data, frame.payload().data(), brytecFrame.dlc);

        Brytec::EBrytecApp::canReceived(0, brytecFrame);
    }

    emit onNovaDataChanged();
}

void NovaCanControl::writeFrame(const Brytec::CanFrame& brytecFrame)
{
    QByteArray arr((const char*)brytecFrame.data, brytecFrame.dlc);
    QCanBusFrame frame(brytecFrame.id, arr);
    m_can1->writeFrame(frame);
}















