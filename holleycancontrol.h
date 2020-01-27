#ifndef HOLLEYCANCONTROL_H
#define HOLLEYCANCONTROL_H

#include <QObject>
#include "spi_can.h"
#include <QQmlContext>
#include <QTimer>
#include "holleycanmodel.h"
#include <QVector>

class HolleyCanControl : public QObject
{
    Q_OBJECT

    static HolleyCanControl* s_holleyCanControl;
    CanLib m_can0;
    QQmlContext* m_context;
    QTimer* m_timer;
    HolleyCanModel m_model;

    QVector<int> m_ignoreIds;

public:
    explicit HolleyCanControl(QQmlContext* context, QObject *parent = nullptr);

signals:
    void MsgFromISR(CanMsg msg);

public slots:
    static HolleyCanControl* get() { return s_holleyCanControl; }
    void handleResult(CanMsg msg);
    CanLib& getCan0() { return m_can0; }
    HolleyCanModel& getHolleyModel() { return m_model; }
    void updateHolleyData();
    void startCan();

};

void holleyCanISR();

#endif // HOLLEYCANCONTROL_H
