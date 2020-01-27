#include "spi.h"

#include "wiringPiSPI.h"
#include <QtDebug>

Spi::Spi(int channel, QObject *parent) : QObject(parent), m_channel(channel)
{

}

void Spi::spiInit()
{
#ifdef RASPPI
    // 8 Mhz
    m_fd = wiringPiSPISetup(m_channel, 8000000);
    if(m_fd < 0)
        qDebug() << "Spi Problem at setup";
#endif
}

//void Spi::SSEnable()
//{

//}

//void Spi::SSDisable()
//{

//}

unsigned char Spi::SpiTransfer(unsigned char data)
{
#ifdef RASPPI
    wiringPiSPIDataRW (m_channel, &data, 1);
    return data;
#endif
}

QVector<unsigned char> Spi::SpiTransfer(QVector<unsigned char> data)
{
    wiringPiSPIDataRW(m_channel, data.data(), data.length());
    return data;
}
