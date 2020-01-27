#ifndef QTCANCONTROL_H
#define QTCANCONTROL_H

#include <QObject>
#include <QCanBus>

class QtCanControl : public QObject
{
    Q_OBJECT

    QCanBusDevice* m_can0;

public:
    explicit QtCanControl(QObject *parent = nullptr);

signals:

public slots:
    void connectToCan();
    void readFame();
};

#endif // QTCANCONTROL_H
