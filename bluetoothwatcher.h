#ifndef BLUETOOTHWATCHER_H
#define BLUETOOTHWATCHER_H

#include <QObject>
#include <QTimer>
#include <QProcess>

class BluetoothWatcher : public QObject
{
    Q_OBJECT

    QTimer* m_timer;
    QProcess* m_process;
    bool m_phoneNear = false;

public:
    explicit BluetoothWatcher(QObject *parent = nullptr);
    ~BluetoothWatcher();

signals:

public slots:
    void startLooking();
    void checkName();

private:
    void setupTimer();

};

#endif // BLUETOOTHWATCHER_H
