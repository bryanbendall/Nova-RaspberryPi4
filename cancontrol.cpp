#include "cancontrol.h"

#include <QDebug>
#include <QTimer>
#include "wiringPi.h"
#include <QThread>

CanControl* CanControl::s_canControl = nullptr;

CanControl::CanControl(QObject *parent)
    : QObject(parent), m_can0(0, CanSpeed::CAN_1_MBPS, CanId::EXT, 0, 0), m_holleyData(49)
{
    qRegisterMetaType<CanMsg>();

    QThread* thread = new QThread(this);
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SIGNAL(updateHolleyData()));
    m_timer->setInterval(33);
    m_timer->moveToThread(thread);
    connect(thread, SIGNAL(started()), m_timer, SLOT(start()));
    thread->start();

    s_canControl = this;
#ifdef RASPPI
    qDebug() << "wiring pi isr: " << wiringPiISR(17, INT_EDGE_FALLING, &canISR);
#endif
}

CanControl::~CanControl()
{
    m_timer->stop();
}

void CanControl::handleResult(CanMsg msg)
{
    unsigned int raw1 = msg.data0;
    raw1 = (raw1 << 8) + msg.data1;
    raw1 = (raw1 << 8) + msg.data2;
    raw1 = (raw1 << 8) + msg.data3;
    unsigned int raw2 = msg.data4;
    raw2 = (raw2 << 8) + msg.data5;
    raw2 = (raw2 << 8) + msg.data6;
    raw2 = (raw2 << 8) + msg.data7;
    float data1 = raw1 / 256.0f;
    float data2 = raw2 / 256.0f;

    unsigned long address = msg.id & 0x1FFC000;
    switch (address) {
        case 0x0000:
            m_holleyData[0] = data2;
//            emit onData0Changed();
            break;
        case 0x4000:
            m_holleyData[1] = data1;
            m_holleyData[2] = data2;
//            emit onData2Changed();
            break;
        case 0x8000:
            m_holleyData[3] = data1;
            m_holleyData[4] = data2;
//            emit onData4Changed();
            break;
        case 0xC000:
            m_holleyData[5] = data1;
            m_holleyData[6] = data2;
//            emit onData6Changed();
            break;
        case 0x10000:
            m_holleyData[7] = data1;
            m_holleyData[8] = data2;
//            emit onData8Changed();
            break;
        case 0x14000:
            m_holleyData[9] = data1;
            m_holleyData[10] = data2;
//            emit onData10Changed();
            break;
        case 0x18000:
            m_holleyData[11] = data1;
            m_holleyData[12] = data2;
//            emit onData12Changed();
            break;
        case 0x1C000:
            m_holleyData[13] = data1;
            m_holleyData[14] = data2;
//            emit onData14Changed();
            break;
        case 0x20000:
            m_holleyData[15] = data1;
            m_holleyData[16] = data2;
//            emit onData16Changed();
            break;
        case 0x24000:
            m_holleyData[17] = data1;
            m_holleyData[18] = data2;
//            emit onData18Changed();
            break;
        case 0x28000:
            m_holleyData[19] = data1;
            m_holleyData[20] = data2;
//            emit onData20Changed();
            break;
        case 0x2C000:
            m_holleyData[21] = data1;
            m_holleyData[22] = data2;
//            emit onData22Changed();
            break;
        case 0x30000:
            m_holleyData[23] = data1;
            m_holleyData[24] = data2;
//            emit onData24Changed();
            break;
        case 0x34000:
            m_holleyData[25] = data1;
            m_holleyData[26] = data2;
//            emit onData26Changed();
            break;
        case 0x38000:
            m_holleyData[27] = data1;
            m_holleyData[28] = data2;
//            emit onData28Changed();
            break;
        case 0x3C000:
            m_holleyData[29] = data1;
            m_holleyData[30] = data2;
//            emit onData30Changed();
            break;
        case 0x40000:
            m_holleyData[31] = data1;
            m_holleyData[32] = data2;
//            emit onData32Changed();
            break;
        case 0x44000:
            m_holleyData[33] = data1;
            m_holleyData[34] = data2;
//            emit onData34Changed();
            break;
        case 0x48000:
            m_holleyData[35] = data1;
            m_holleyData[36] = data2;
//            emit onData36Changed();
            break;
        case 0x4C000:
            m_holleyData[37] = data1;
            m_holleyData[38] = data2;
//            emit onData38Changed();
            break;
        case 0x50000:
            m_holleyData[39] = data1;
            m_holleyData[40] = data2;
//            emit onData40Changed();
            break;
        case 0x54000:
            m_holleyData[41] = data1;
            m_holleyData[42] = data2;
//            emit onData42Changed();
            break;
        case 0x58000:
            m_holleyData[43] = data1;
            m_holleyData[44] = data2;
//            emit onData44Changed();
            break;
        case 0x5C000:
            m_holleyData[45] = data1;
            m_holleyData[46] = data2;
//            emit onData46Changed();
            break;
        case 0x60000:
            m_holleyData[47] = data1;
            m_holleyData[48] = data2;
//            emit onData48Changed();
            break;
    }
}

void CanControl::startCan()
{
    while(m_can0.Available())
        m_can0.GetCanMsg();

    qDebug() << "done clear out data";
}

void canISR()
{
    CanControl::get()->handleResult(CanControl::get()->getCan0().GetCanMsg());
}
