#include "holleycanmsg.h"

HolleyCanMsg::HolleyCanMsg(int address, int data0, int data1, int data2, int data3,
                           int data4, int data5, int data6, int data7, QString label, QObject *parent)
    : QObject(parent), m_address(address), m_data0(data0), m_data1(data1), m_data2(data2), m_data3(data3),
      m_data4(data4), m_data5(data5), m_data6(data6), m_data7(data7), m_label(label)
{

}
