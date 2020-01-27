#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QObject>

class SerialComm : public QObject
{
    Q_OBJECT

    int m_fd;

public:
    explicit SerialComm(QObject *parent = nullptr);
    void sendData(unsigned char data);

signals:
    void dataAvailable(int data);

public slots:
    void checkSerialData();
};

#endif // SERIALCOMM_H
