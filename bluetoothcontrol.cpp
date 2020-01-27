//#include "bluetoothcontrol.h"
//#include <QDebug>

//BluetoothControl::BluetoothControl(QObject *parent) : QObject(parent)
//{

//}

//void BluetoothControl::start()
//{
//    // Create a discovery agent and connect to its signals
//        m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
//        m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(0);

//        connect(m_deviceDiscoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
//        connect(m_deviceDiscoveryAgent, SIGNAL(finished()), this, SLOT(finished()));
//        connect(m_deviceDiscoveryAgent, SIGNAL(canceled()), this, SLOT(finished()));

//        // Start a discovery
//        m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);

//        qDebug() << "starting search";




////    QString uuid = "ad0a65ff-0000-1000-8000-00805f9b34fb";
////    QBluetoothDeviceInfo di((QBluetoothUuid(uuid)), "Nova", 0);
////    m_control = QLowEnergyController::createCentral(di, this);

////    connect(m_control, SIGNAL(connected()), this, SLOT(connected()));
////    connect(m_control, SIGNAL(disconnected()), this, SLOT(disconnected()));

////    connect(m_control, static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
////            this, [](QLowEnergyController::Error error) {
////        qDebug() << "Cannot connect to remote device. " << QString::number(error);
////    });

////    m_control->connectToDevice();
//}

//void BluetoothControl::deviceDiscovered(const QBluetoothDeviceInfo &device)
//{
////    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ") - " << device.rssi();

//    if (device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) {
//        QBluetoothDeviceInfo *d = new QBluetoothDeviceInfo(device);
//        m_device = d;
//        qDebug() << "Last device added: " + d->name() + " " + d->deviceUuid().toString() + " " + QString::number((qulonglong)d->deviceUuid().toUInt128().data, 16);
//        qDebug() << "device rssi " << QString::number(d->rssi());
//    }

//    if(device.name() == "Pixel"){
//        qDebug() << "trying to connect";

//        m_control = QLowEnergyController::createCentral(device, this);
//        connect(m_control, SIGNAL(connected()), this, SLOT(connected()));
//        connect(m_control, SIGNAL(disconnected()), this, SLOT(disconnected()));

//        connect(m_control, static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
//                this, [](QLowEnergyController::Error error) {
//            qDebug() << "Cannot connect to remote device. " << QString::number(error);
//        });
//        connect(m_control, SIGNAL(stateChanged()), this, SLOT(stateChanged()));

////        if (device.isRandomAddress())
////              m_control->setRemoteAddressType(QLowEnergyController::RandomAddress);
////          else
////              m_control->setRemoteAddressType(QLowEnergyController::PublicAddress);

//        m_control->connectToDevice();
//    }

//}

//void BluetoothControl::finished()
//{
//    qDebug() << "finished bt scan";
//}

//void BluetoothControl::connected()
//{
//    qDebug() << "connected!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
//    qDebug() << "connected rssi " << QString::number(m_device->rssi());
//}

//void BluetoothControl::disconnected()
//{
//    qDebug() << "disconnected!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
//}

//void BluetoothControl::stateChanged(QLowEnergyController::ControllerState state)
//{
//    QString msg;

//    switch (state) {
//    case QLowEnergyController::ControllerState::UnconnectedState:
//        msg = "UnconnectedState";
//        break;
//    case QLowEnergyController::ControllerState::ConnectingState:
//        msg = "ConnectingState";
//        break;
//    case QLowEnergyController::ControllerState::ConnectedState:
//        msg = "ConnectedState";
//        break;
//    case QLowEnergyController::ControllerState::DiscoveringState:
//        msg = "DiscoveringState";
//        break;
//    case QLowEnergyController::ControllerState::DiscoveredState:
//        msg = "DiscoveredState";
//        break;
//    case QLowEnergyController::ControllerState::ClosingState:
//        msg = "ClosingState";
//        break;
//    case QLowEnergyController::ControllerState::AdvertisingState:
//        msg = "AdvertisingState";
//        break;
//    }
//    qDebug() << "state changed: " << msg;
//}

