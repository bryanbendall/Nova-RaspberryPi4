#include "bluetoothwatcher.h"

#include <QDebug>
#include <QThread>

BluetoothWatcher::BluetoothWatcher(QObject *parent) : QObject(parent)
{
#ifdef RASPPI
    QMetaObject::invokeMethod(this, &BluetoothWatcher::setupTimer, Qt::QueuedConnection);
#endif
}

BluetoothWatcher::~BluetoothWatcher()
{
    m_timer->stop();
    delete m_timer;
}

void BluetoothWatcher::startLooking()
{
    m_process = new QProcess(this);
    m_process->start("hcitool", QStringList() << "name" << "AC:37:43:BC:69:5E");
    connect(m_process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(checkName()));
}

void BluetoothWatcher::checkName()
{
    if(m_process->readAllStandardOutput() == "Pixel\n"){
        if(m_phoneNear)
            return;
        qDebug() << "found phone";
        m_phoneNear = true;
    } else {
        if(!m_phoneNear)
            return;
        qDebug() << "lost phone";
        m_phoneNear = false;
    }
}

void BluetoothWatcher::setupTimer()
{
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(startLooking()));
    m_timer->start(3000);
}

