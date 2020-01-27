#ifndef SPI_H
#define SPI_H

#include <QObject>
#include <QVector>

class Spi : public QObject
{
    Q_OBJECT

    int m_channel;
    int m_fd;

public:
    explicit Spi(int channel, QObject *parent = nullptr);

    //To change
    void spiInit();
//    void SSEnable();
//    void SSDisable();
    unsigned char SpiTransfer(unsigned char data);
    QVector<unsigned char> SpiTransfer(QVector<unsigned char> data);
    //

signals:

public slots:
};

#endif // SPI_H
