#ifndef CANCONTROLLER_H
#define CANCONTROLLER_H

#include <QObject>
#include "spi_can.h"
#include <QTimer>

class CanControl : public QObject
{
    Q_OBJECT

    QTimer* m_timer;

    static CanControl* s_canControl;
    CanLib m_can0;

    QVector<float> m_holleyData;

    Q_PROPERTY(float rpm READ rpm                       NOTIFY updateHolleyData)
    Q_PROPERTY(float pulseWidth READ pulseWidth         NOTIFY updateHolleyData)
    Q_PROPERTY(float fuelFlow READ fuelFlow             NOTIFY updateHolleyData)
    Q_PROPERTY(float closedLoop READ closedLoop         NOTIFY updateHolleyData)
    Q_PROPERTY(float dutyCycle READ dutyCycle           NOTIFY updateHolleyData)
    Q_PROPERTY(float afrLeft READ afrLeft               NOTIFY updateHolleyData)
    Q_PROPERTY(float closedLoopComp READ closedLoopComp NOTIFY updateHolleyData)
    Q_PROPERTY(float afrTarget READ afrTarget           NOTIFY updateHolleyData)
    Q_PROPERTY(float afrRight READ afrRight             NOTIFY updateHolleyData)
    Q_PROPERTY(float timing READ timing                 NOTIFY updateHolleyData)
    Q_PROPERTY(float afrAverage READ afrAverage         NOTIFY updateHolleyData)
    Q_PROPERTY(float map READ map                       NOTIFY updateHolleyData)
    Q_PROPERTY(float knockRetard READ knockRetard       NOTIFY updateHolleyData)
    Q_PROPERTY(float mat READ mat                       NOTIFY updateHolleyData)
    Q_PROPERTY(float tps READ tps                       NOTIFY updateHolleyData)
    Q_PROPERTY(float baro READ baro                     NOTIFY updateHolleyData)
    Q_PROPERTY(float cts READ cts                       NOTIFY updateHolleyData)
    Q_PROPERTY(float oilPress READ oilPress             NOTIFY updateHolleyData)
    Q_PROPERTY(float batteryVolt READ batteryVolt       NOTIFY updateHolleyData)
    Q_PROPERTY(float pedalPos READ pedalPos             NOTIFY updateHolleyData)
    Q_PROPERTY(float fuelPress READ fuelPress           NOTIFY updateHolleyData)
    Q_PROPERTY(float boostGear READ boostGear           NOTIFY updateHolleyData)
    Q_PROPERTY(float mainRevLimit READ mainRevLimit     NOTIFY updateHolleyData)
    Q_PROPERTY(float boostSpeed READ boostSpeed         NOTIFY updateHolleyData)
    Q_PROPERTY(float boostStage READ boostStage         NOTIFY updateHolleyData)
    Q_PROPERTY(float boostTarget READ boostTarget       NOTIFY updateHolleyData)
    Q_PROPERTY(float boostTime READ boostTime           NOTIFY updateHolleyData)
    Q_PROPERTY(float boostSolDuty READ boostSolDuty     NOTIFY updateHolleyData)
    Q_PROPERTY(float boost READ boost                   NOTIFY updateHolleyData)
    Q_PROPERTY(float n20Stage1 READ n20Stage1           NOTIFY updateHolleyData)
    Q_PROPERTY(float waterMeth READ waterMeth           NOTIFY updateHolleyData)
    Q_PROPERTY(float n20Stage3 READ n20Stage3           NOTIFY updateHolleyData)
    Q_PROPERTY(float n20Stage2 READ n20Stage2           NOTIFY updateHolleyData)
    Q_PROPERTY(float gear READ gear                     NOTIFY updateHolleyData)
    Q_PROPERTY(float n20Stage4 READ n20Stage4           NOTIFY updateHolleyData)
    Q_PROPERTY(float linePress READ linePress           NOTIFY updateHolleyData)
    Q_PROPERTY(float speed READ speed                   NOTIFY updateHolleyData)
    Q_PROPERTY(float inputShaftSpeed READ inputShaftSpeed NOTIFY updateHolleyData)
    Q_PROPERTY(float lineTemp READ lineTemp             NOTIFY updateHolleyData)
    Q_PROPERTY(float input2 READ input2                 NOTIFY updateHolleyData)
    Q_PROPERTY(float input1 READ input1                 NOTIFY updateHolleyData)
    Q_PROPERTY(float input4 READ input4                 NOTIFY updateHolleyData)
    Q_PROPERTY(float input3 READ input3                 NOTIFY updateHolleyData)
    Q_PROPERTY(float output1 READ output1               NOTIFY updateHolleyData)
    Q_PROPERTY(float input5 READ input5                 NOTIFY updateHolleyData)
    Q_PROPERTY(float output3 READ output3               NOTIFY updateHolleyData)
    Q_PROPERTY(float output2 READ output2               NOTIFY updateHolleyData)
    Q_PROPERTY(float output5 READ output5               NOTIFY updateHolleyData)
    Q_PROPERTY(float output4 READ output4               NOTIFY updateHolleyData)

public:
    explicit CanControl(QObject *parent = nullptr);
    ~CanControl();

    const float& rpm()             {return m_holleyData[0];}
    const float& pulseWidth()      {return m_holleyData[1];}
    const float& fuelFlow()        {return m_holleyData[2];}
    const float& closedLoop()      {return m_holleyData[3];}
    const float& dutyCycle()       {return m_holleyData[4];}
    const float& afrLeft()         {return m_holleyData[5];}
    const float& closedLoopComp()  {return m_holleyData[6];}
    const float& afrTarget()       {return m_holleyData[7];}
    const float& afrRight()        {return m_holleyData[8];}
    const float& timing()          {return m_holleyData[9];}
    const float& afrAverage()      {return m_holleyData[10];}
    const float& map()             {return m_holleyData[11];}
    const float& knockRetard()     {return m_holleyData[12];}
    const float& mat()             {return m_holleyData[13];}
    const float& tps()             {return m_holleyData[14];}
    const float& baro()            {return m_holleyData[15];}
    const float& cts()             {return m_holleyData[16];}
    const float& oilPress()        {return m_holleyData[17];}
    const float& batteryVolt()     {return m_holleyData[18];}
    const float& pedalPos()        {return m_holleyData[19];}
    const float& fuelPress()       {return m_holleyData[20];}
    const float& boostGear()       {return m_holleyData[21];}
    const float& mainRevLimit()    {return m_holleyData[22];}
    const float& boostSpeed()      {return m_holleyData[23];}
    const float& boostStage()      {return m_holleyData[24];}
    const float& boostTarget()     {return m_holleyData[25];}
    const float& boostTime()       {return m_holleyData[26];}
    const float& boostSolDuty()    {return m_holleyData[27];}
    const float& boost()           {return m_holleyData[28];}
    const float& n20Stage1()       {return m_holleyData[29];}
    const float& waterMeth()       {return m_holleyData[30];}
    const float& n20Stage3()       {return m_holleyData[31];}
    const float& n20Stage2()       {return m_holleyData[32];}
    const float& gear()            {return m_holleyData[33];}
    const float& n20Stage4()       {return m_holleyData[34];}
    const float& linePress()       {return m_holleyData[35];}
    const float& speed()           {return m_holleyData[36];}
    const float& inputShaftSpeed() {return m_holleyData[37];}
    const float& lineTemp()        {return m_holleyData[38];}
    const float& input2()          {return m_holleyData[39];}
    const float& input1()          {return m_holleyData[40];}
    const float& input4()          {return m_holleyData[41];}
    const float& input3()          {return m_holleyData[42];}
    const float& output1()         {return m_holleyData[43];}
    const float& input5()          {return m_holleyData[44];}
    const float& output3()         {return m_holleyData[45];}
    const float& output2()         {return m_holleyData[46];}
    const float& output5()         {return m_holleyData[47];}
    const float& output4()         {return m_holleyData[48];}

signals:
    void updateHolleyData();

public slots:
    void handleResult(CanMsg msg);
    void startCan();
    static CanControl* get() { return s_canControl; }
    CanLib& getCan0() { return m_can0; }
};

void canISR();

#endif // CANCONTROLLER_H
