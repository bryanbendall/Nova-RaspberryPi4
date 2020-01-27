#include "datareciever.h"
#include <QtDebug>
#include "tabcommdefs.h"

DataReciever::DataReciever(SerialComm *serial, QObject *lights, QObject *parent) : QObject(parent), m_lights(lights)
{
    connect(serial, SIGNAL(dataAvailable(int)), this, SLOT(recieveData(int)));
}

void DataReciever::recieveData(int data)
{
//    qDebug() << "recieved data - " << data;

    if(!m_data1){
        m_data1 = data;
        return;
    }

    switch(m_data1) {
        case TAB_LIGHT_RUNNING:
            m_lights->setProperty("running", data);
            break;
        case TAB_LIGHT_PARKING:
            m_lights->setProperty("parking", data);
            break;
        case TAB_LIGHT_LOW_BEAM:
            m_lights->setProperty("lowBeam", data);
            break;
        case TAB_LIGHT_HIGH_BEAM:
            m_lights->setProperty("highBeam", data);
            break;
        case TAB_LIGHT_INTERIOR:
            m_lights->setProperty("interior", data);
            break;
        default:
            break;
    }

    m_data1 = 0;
}
