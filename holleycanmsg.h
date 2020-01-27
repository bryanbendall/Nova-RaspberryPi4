#ifndef HOLLEYCANMSG_H
#define HOLLEYCANMSG_H

#include <QObject>

class HolleyCanMsg : public QObject
{
    Q_OBJECT

    int m_address;
    int m_data0;
    int m_data1;
    int m_data2;
    int m_data3;
    int m_data4;
    int m_data5;
    int m_data6;
    int m_data7;
    QString m_label;

    Q_PROPERTY(int address MEMBER m_address NOTIFY manualDataUpdate)
    Q_PROPERTY(int data0 MEMBER m_data0 NOTIFY manualDataUpdate)
    Q_PROPERTY(int data1 MEMBER m_data1 NOTIFY manualDataUpdate)
    Q_PROPERTY(int data2 MEMBER m_data2 NOTIFY manualDataUpdate)
    Q_PROPERTY(int data3 MEMBER m_data3 NOTIFY manualDataUpdate)
    Q_PROPERTY(int data4 MEMBER m_data4 NOTIFY manualDataUpdate)
    Q_PROPERTY(int data5 MEMBER m_data5 NOTIFY manualDataUpdate)
    Q_PROPERTY(int data6 MEMBER m_data6 NOTIFY manualDataUpdate)
    Q_PROPERTY(int data7 MEMBER m_data7 NOTIFY manualDataUpdate)
    Q_PROPERTY(QString label MEMBER m_label NOTIFY manualDataUpdate)

public:
    explicit HolleyCanMsg(int address,
                          int data0,
                          int data1,
                          int data2,
                          int data3,
                          int data4,
                          int data5,
                          int data6,
                          int data7,
                          QString label,
                          QObject *parent = nullptr);

    void setAddress(int addr) {m_address = addr;}
    void setData0(int d) {m_data0 = d;}
    void setData1(int d) {m_data1 = d;}
    void setData2(int d) {m_data2 = d;}
    void setData3(int d) {m_data3 = d;}
    void setData4(int d) {m_data4 = d;}
    void setData5(int d) {m_data5 = d;}
    void setData6(int d) {m_data6 = d;}
    void setData7(int d) {m_data7 = d;}
    void setLabel(QString label) {m_label = label;}

signals:
//    void addressChanged();
//    void data0Changed();
//    void data1Changed();
//    void data2Changed();
//    void data3Changed();
//    void data4Changed();
//    void data5Changed();
//    void data6Changed();
//    void data7Changed();
    void manualDataUpdate();

public slots:
};

#endif // HOLLEYCANMSG_H
