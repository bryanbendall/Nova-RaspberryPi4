#ifndef DATARECIEVER_H
#define DATARECIEVER_H

#include <QObject>
#include "serialcomm.h"

class DataReciever : public QObject
{
    Q_OBJECT
    QObject* m_lights;
    int m_data1 = 0;

public:
    explicit DataReciever(SerialComm* serial, QObject* lights, QObject *parent = nullptr);

signals:

public slots:
    void recieveData(int data);

};

#endif // DATARECIEVER_H
