#include "holleycancontrol.h"
#include <QVariant>
#include <QThread>
#include "holleycanmsg.h"
#include <QDebug>
#include "wiringPi.h"

HolleyCanControl* HolleyCanControl::s_holleyCanControl = nullptr;

HolleyCanControl::HolleyCanControl(QQmlContext* context, QObject *parent)
    : QObject(parent), m_can0(0, CanSpeed::CAN_1_MBPS, CanId::EXT, 0, 0), m_context(context)
{
//    m_ignoreIds.push_back(503485426);
//    m_ignoreIds.push_back(504321010);
//    m_ignoreIds.push_back(504271858);
//    m_ignoreIds.push_back(504222706);
//    m_ignoreIds.push_back(504157170);
//    m_ignoreIds.push_back(504091634);
//    m_ignoreIds.push_back(503714802);
//    m_ignoreIds.push_back(503632882);
//    m_ignoreIds.push_back(503583730);
//    m_ignoreIds.push_back(503534578);

//    m_ignoreIds.push_back(503370738);
//    m_ignoreIds.push_back(507925490);
//    m_ignoreIds.push_back(507876338);
//    m_ignoreIds.push_back(507335666);
//    m_ignoreIds.push_back(507089906);
//    m_ignoreIds.push_back(506909682);
//    m_ignoreIds.push_back(505861106);
//    m_ignoreIds.push_back(505631730);
//    m_ignoreIds.push_back(505304050);
//    m_ignoreIds.push_back(505140210);
//    m_ignoreIds.push_back(505041906);
//    m_ignoreIds.push_back(504943602);


    qRegisterMetaType<CanMsg>();

    QThread* thread = new QThread(this);
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateHolleyData()));
    m_timer->setInterval(50);
    m_timer->moveToThread(thread);
    connect(thread, SIGNAL(started()), m_timer, SLOT(start()));
    thread->start();

    connect(this, SIGNAL(MsgFromISR(CanMsg)), this, SLOT(handleResult(CanMsg)));

    s_holleyCanControl = this;
#ifdef RASPPI
    qDebug() << "wiring pi isr: " << wiringPiISR(17, INT_EDGE_FALLING, &holleyCanISR);
#endif

//    m_model.insert(new HolleyCanMsg("test", "1", "2", "3", "4", "5", "6", "7", "8", this));

}

void HolleyCanControl::handleResult(CanMsg msg)
{
//    for(int j = 0; j < m_ignoreIds.length(); j++){
//        if((int)msg.id == m_ignoreIds[j]){
//            return;
//        }
//    }

    for(int i = 0; i < m_model.rowCount(QModelIndex()); i++){
        QObject* obj = m_model.data(m_model.index(i), 1).value<QObject*>();

        if(obj->property("address").toInt() == (int)msg.id){

            HolleyCanMsg* canMsg = (HolleyCanMsg*)obj;
//            canMsg->setData0(msg.data0);
//            canMsg->setData1(msg.data1);
//            canMsg->setData2(msg.data2);
//            canMsg->setData3(msg.data3);
//            canMsg->setData4(msg.data4);
//            canMsg->setData5(msg.data5);
//            canMsg->setData6(msg.data6);
//            canMsg->setData7(msg.data7);

            unsigned long temp = (msg.data0 << 24) | (msg.data1 << 16) | (msg.data2 << 8) | msg.data3;
            float f = *((float*)&temp);
            int index = (msg.id & 0x1FFC000) >> 14;

            switch (index) {
            case 1:
                canMsg->setLabel("index " + QString::number(index) + " rpm " + QString::number(f) );
                break;
            case 2:
                canMsg->setLabel("index " + QString::number(index) + " inj pluse width " + QString::number(f) );
                break;
            case 3:
                canMsg->setLabel("index " + QString::number(index) + " duty cycle " + QString::number(f) );
                break;
            case 4:
                canMsg->setLabel("index " + QString::number(index) + " cl comp " + QString::number(f) );
                break;
            case 5:
                canMsg->setLabel("index " + QString::number(index) + " target afr " + QString::number(f) );
                break;
            case 6:
                canMsg->setLabel("index " + QString::number(index) + " afr left " + QString::number(f) );
                break;
            case 26:
                canMsg->setLabel("index " + QString::number(index) + " map " + QString::number(f) );
                break;
            case 27:
                canMsg->setLabel("index " + QString::number(index) + " tps " + QString::number(f) );
                break;
            case 28:
                canMsg->setLabel("index " + QString::number(index) + " mat " + QString::number(f) );
                break;
            case 29:
                canMsg->setLabel("index " + QString::number(index) + " cts " + QString::number(f) );
                break;

            default:
                canMsg->setLabel("index " + QString::number(index) + " data " + QString::number(f) );
            }

//            if(msg.id == 507171826)
//                canMsg->setLabel("pedal tps #2 " + QString::number(f));

//            if(msg.id == 507155442)
//                canMsg->setLabel("pedal tps #1 " + QString::number(f));

            return;
        }
    }

    int index = (msg.id & 0x1FFC000) >> 14;
    if((index > 0 && index < 7) || (index > 25 && index < 30)){
        m_model.insert(new HolleyCanMsg(msg.id,
                                                 msg.data0,
                                                 msg.data1,
                                                 msg.data2,
                                                 msg.data3,
                                                 msg.data4,
                                                 msg.data5,
                                                 msg.data6,
                                                 msg.data7,
                                                 nullptr));
    }

//    if(m_model.rowCount(QModelIndex()) > 15)
//        return;

//    m_model.insert(new HolleyCanMsg(msg.id,
//                                             msg.data0,
//                                             msg.data1,
//                                             msg.data2,
//                                             msg.data3,
//                                             msg.data4,
//                                             msg.data5,
//                                             msg.data6,
//                                             msg.data7,
//                                             nullptr));
}

void HolleyCanControl::updateHolleyData()
{
    for(int i = 0; i < m_model.rowCount(QModelIndex()); i++){

        QObject* obj = m_model.data(m_model.index(i), 1).value<QObject*>();
        HolleyCanMsg* canMsg = (HolleyCanMsg*)obj;
        canMsg->manualDataUpdate();
    }
}

void HolleyCanControl::startCan()
{
    while(m_can0.Available())
        m_can0.GetCanMsg();

    qDebug() << "done clear out data";
}

void holleyCanISR()
{
    HolleyCanControl::get()->MsgFromISR(HolleyCanControl::get()->getCan0().GetCanMsg());
}
