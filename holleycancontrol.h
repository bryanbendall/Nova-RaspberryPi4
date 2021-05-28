#ifndef HOLLEYCANCONTROL_H
#define HOLLEYCANCONTROL_H

#include <QObject>
#include <QCanBus>
#include <QVector>
#include <QtDebug>
#include <QTimer>

class HolleyCanControl : public QObject
{
    Q_OBJECT

    QCanBusDevice* m_can;
    QTimer* m_timer;
    bool m_setupDone = false;
    float m_data[511] = {0.0f};
    QVector<unsigned int> m_filterId;

public:
    explicit HolleyCanControl(QObject *parent = nullptr);
    ~HolleyCanControl();

signals:
    void onHolleyDataChanged();

public slots:
    void connectToCan();
    void readFrame();

private:
    void setupFilters();
    float getFloat(QCanBusFrame& frame);
    void registerFilter(unsigned int filter);

    double m_odometer = 0.0;
    Q_PROPERTY(double Odometer MEMBER m_odometer NOTIFY onHolleyDataChanged)

#if defined(HOLLEYV4)
    #include "holleyvariablesv4.h"
#elif defined(HOLLEYV6)
    #include "holleyvariablesv6.h"
#endif

};

#endif // HOLLEYCANCONTROL_H
