#ifndef NOVACANCONTROL_H
#define NOVACANCONTROL_H

#include <QObject>
#include <QCanBus>
#include <QTimer>

class NovaCanControl : public QObject
{
    Q_OBJECT

    QCanBusDevice* m_can1;
    QTimer* m_timer;

public:
    explicit NovaCanControl(QObject *parent = nullptr);
    ~NovaCanControl();

signals:
    void onNovaDataChanged();

public slots:
    void connectToCan();
    void readFrame();

};

#endif // NOVACANCONTROL_H
