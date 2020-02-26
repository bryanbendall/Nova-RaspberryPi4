#ifndef RACEPAKCANCONTROL_H
#define RACEPAKCANCONTROL_H

#include <QObject>
#include <QCanBus>
#include <QTimer>

class RacepakCanControl : public QObject
{
    Q_OBJECT

    QCanBusDevice* m_can1;
    QTimer* m_timer;

    float m_outputAmps[30] = {0.0f};
    float m_outputVolts[30] = {0.0f};
    unsigned int m_outputStatus[30] = {0};
    bool m_inputStatus[12] = {false};

public:
    explicit RacepakCanControl(QObject *parent = nullptr);
    ~RacepakCanControl();

signals:
    void onRacepakDataChanged();

public slots:
    void connectToCan();
    void readFrame();

private:
    void decodeSwitches(QCanBusFrame& frame);
    void decodeOutput(QCanBusFrame& frame);

    Q_PROPERTY(float Output_1_Amps 		READ Output_1_Amps 		NOTIFY onRacepakDataChanged) const float& Output_1_Amps() 		{return m_outputAmps[0];}
    Q_PROPERTY(float Output_2_Amps 		READ Output_2_Amps 		NOTIFY onRacepakDataChanged) const float& Output_2_Amps() 		{return m_outputAmps[1];}
    Q_PROPERTY(float Output_3_Amps 		READ Output_3_Amps 		NOTIFY onRacepakDataChanged) const float& Output_3_Amps() 		{return m_outputAmps[2];}
    Q_PROPERTY(float Output_4_Amps 		READ Output_4_Amps 		NOTIFY onRacepakDataChanged) const float& Output_4_Amps() 		{return m_outputAmps[3];}
    Q_PROPERTY(float Output_5_Amps 		READ Output_5_Amps 		NOTIFY onRacepakDataChanged) const float& Output_5_Amps() 		{return m_outputAmps[4];}
    Q_PROPERTY(float Output_6_Amps 		READ Output_6_Amps 		NOTIFY onRacepakDataChanged) const float& Output_6_Amps() 		{return m_outputAmps[5];}
    Q_PROPERTY(float Output_7_Amps 		READ Output_7_Amps 		NOTIFY onRacepakDataChanged) const float& Output_7_Amps() 		{return m_outputAmps[6];}
    Q_PROPERTY(float Output_8_Amps 		READ Output_8_Amps 		NOTIFY onRacepakDataChanged) const float& Output_8_Amps() 		{return m_outputAmps[7];}
    Q_PROPERTY(float Output_9_Amps 		READ Output_9_Amps 		NOTIFY onRacepakDataChanged) const float& Output_9_Amps() 		{return m_outputAmps[8];}
    Q_PROPERTY(float Output_10_Amps 	READ Output_10_Amps 	NOTIFY onRacepakDataChanged) const float& Output_10_Amps() 		{return m_outputAmps[9];}
    Q_PROPERTY(float Output_11_Amps 	READ Output_11_Amps 	NOTIFY onRacepakDataChanged) const float& Output_11_Amps() 		{return m_outputAmps[10];}
    Q_PROPERTY(float Output_12_Amps 	READ Output_12_Amps 	NOTIFY onRacepakDataChanged) const float& Output_12_Amps() 		{return m_outputAmps[11];}
    Q_PROPERTY(float Output_13_Amps 	READ Output_13_Amps 	NOTIFY onRacepakDataChanged) const float& Output_13_Amps() 		{return m_outputAmps[12];}
    Q_PROPERTY(float Output_14_Amps 	READ Output_14_Amps 	NOTIFY onRacepakDataChanged) const float& Output_14_Amps() 		{return m_outputAmps[13];}
    Q_PROPERTY(float Output_15_Amps 	READ Output_15_Amps 	NOTIFY onRacepakDataChanged) const float& Output_15_Amps() 		{return m_outputAmps[14];}
    Q_PROPERTY(float Output_16_Amps 	READ Output_16_Amps 	NOTIFY onRacepakDataChanged) const float& Output_16_Amps() 		{return m_outputAmps[15];}
    Q_PROPERTY(float Output_17_Amps 	READ Output_17_Amps 	NOTIFY onRacepakDataChanged) const float& Output_17_Amps() 		{return m_outputAmps[16];}
    Q_PROPERTY(float Output_18_Amps 	READ Output_18_Amps 	NOTIFY onRacepakDataChanged) const float& Output_18_Amps() 		{return m_outputAmps[17];}
    Q_PROPERTY(float Output_19_Amps 	READ Output_19_Amps 	NOTIFY onRacepakDataChanged) const float& Output_19_Amps() 		{return m_outputAmps[18];}
    Q_PROPERTY(float Output_20_Amps 	READ Output_20_Amps 	NOTIFY onRacepakDataChanged) const float& Output_20_Amps() 		{return m_outputAmps[19];}
    Q_PROPERTY(float Output_21_Amps 	READ Output_21_Amps 	NOTIFY onRacepakDataChanged) const float& Output_21_Amps() 		{return m_outputAmps[20];}
    Q_PROPERTY(float Output_22_Amps 	READ Output_22_Amps 	NOTIFY onRacepakDataChanged) const float& Output_22_Amps() 		{return m_outputAmps[21];}
    Q_PROPERTY(float Output_23_Amps 	READ Output_23_Amps 	NOTIFY onRacepakDataChanged) const float& Output_23_Amps() 		{return m_outputAmps[22];}
    Q_PROPERTY(float Output_24_Amps 	READ Output_24_Amps 	NOTIFY onRacepakDataChanged) const float& Output_24_Amps() 		{return m_outputAmps[23];}
    Q_PROPERTY(float Output_25_Amps 	READ Output_25_Amps 	NOTIFY onRacepakDataChanged) const float& Output_25_Amps() 		{return m_outputAmps[24];}
    Q_PROPERTY(float Output_26_Amps 	READ Output_26_Amps 	NOTIFY onRacepakDataChanged) const float& Output_26_Amps() 		{return m_outputAmps[25];}
    Q_PROPERTY(float Output_27_Amps 	READ Output_27_Amps 	NOTIFY onRacepakDataChanged) const float& Output_27_Amps() 		{return m_outputAmps[26];}
    Q_PROPERTY(float Output_28_Amps 	READ Output_28_Amps 	NOTIFY onRacepakDataChanged) const float& Output_28_Amps() 		{return m_outputAmps[27];}
    Q_PROPERTY(float Output_29_Amps 	READ Output_29_Amps 	NOTIFY onRacepakDataChanged) const float& Output_29_Amps() 		{return m_outputAmps[28];}
    Q_PROPERTY(float Output_30_Amps 	READ Output_30_Amps 	NOTIFY onRacepakDataChanged) const float& Output_30_Amps() 		{return m_outputAmps[29];}
    Q_PROPERTY(float Output_1_Volts 	READ Output_1_Volts 	NOTIFY onRacepakDataChanged) const float& Output_1_Volts() 		{return m_outputVolts[0];}
    Q_PROPERTY(float Output_2_Volts 	READ Output_2_Volts 	NOTIFY onRacepakDataChanged) const float& Output_2_Volts() 		{return m_outputVolts[1];}
    Q_PROPERTY(float Output_3_Volts 	READ Output_3_Volts 	NOTIFY onRacepakDataChanged) const float& Output_3_Volts() 		{return m_outputVolts[2];}
    Q_PROPERTY(float Output_4_Volts 	READ Output_4_Volts 	NOTIFY onRacepakDataChanged) const float& Output_4_Volts() 		{return m_outputVolts[3];}
    Q_PROPERTY(float Output_5_Volts 	READ Output_5_Volts 	NOTIFY onRacepakDataChanged) const float& Output_5_Volts() 		{return m_outputVolts[4];}
    Q_PROPERTY(float Output_6_Volts 	READ Output_6_Volts 	NOTIFY onRacepakDataChanged) const float& Output_6_Volts() 		{return m_outputVolts[5];}
    Q_PROPERTY(float Output_7_Volts 	READ Output_7_Volts 	NOTIFY onRacepakDataChanged) const float& Output_7_Volts() 		{return m_outputVolts[6];}
    Q_PROPERTY(float Output_8_Volts 	READ Output_8_Volts 	NOTIFY onRacepakDataChanged) const float& Output_8_Volts() 		{return m_outputVolts[7];}
    Q_PROPERTY(float Output_9_Volts 	READ Output_9_Volts 	NOTIFY onRacepakDataChanged) const float& Output_9_Volts() 		{return m_outputVolts[8];}
    Q_PROPERTY(float Output_10_Volts 	READ Output_10_Volts 	NOTIFY onRacepakDataChanged) const float& Output_10_Volts() 	{return m_outputVolts[9];}
    Q_PROPERTY(float Output_11_Volts 	READ Output_11_Volts 	NOTIFY onRacepakDataChanged) const float& Output_11_Volts() 	{return m_outputVolts[10];}
    Q_PROPERTY(float Output_12_Volts 	READ Output_12_Volts 	NOTIFY onRacepakDataChanged) const float& Output_12_Volts() 	{return m_outputVolts[11];}
    Q_PROPERTY(float Output_13_Volts 	READ Output_13_Volts 	NOTIFY onRacepakDataChanged) const float& Output_13_Volts() 	{return m_outputVolts[12];}
    Q_PROPERTY(float Output_14_Volts 	READ Output_14_Volts 	NOTIFY onRacepakDataChanged) const float& Output_14_Volts() 	{return m_outputVolts[13];}
    Q_PROPERTY(float Output_15_Volts 	READ Output_15_Volts 	NOTIFY onRacepakDataChanged) const float& Output_15_Volts() 	{return m_outputVolts[14];}
    Q_PROPERTY(float Output_16_Volts 	READ Output_16_Volts 	NOTIFY onRacepakDataChanged) const float& Output_16_Volts() 	{return m_outputVolts[15];}
    Q_PROPERTY(float Output_17_Volts 	READ Output_17_Volts 	NOTIFY onRacepakDataChanged) const float& Output_17_Volts() 	{return m_outputVolts[16];}
    Q_PROPERTY(float Output_18_Volts 	READ Output_18_Volts 	NOTIFY onRacepakDataChanged) const float& Output_18_Volts() 	{return m_outputVolts[17];}
    Q_PROPERTY(float Output_19_Volts 	READ Output_19_Volts 	NOTIFY onRacepakDataChanged) const float& Output_19_Volts() 	{return m_outputVolts[18];}
    Q_PROPERTY(float Output_20_Volts 	READ Output_20_Volts 	NOTIFY onRacepakDataChanged) const float& Output_20_Volts() 	{return m_outputVolts[19];}
    Q_PROPERTY(float Output_21_Volts 	READ Output_21_Volts 	NOTIFY onRacepakDataChanged) const float& Output_21_Volts() 	{return m_outputVolts[20];}
    Q_PROPERTY(float Output_22_Volts 	READ Output_22_Volts 	NOTIFY onRacepakDataChanged) const float& Output_22_Volts() 	{return m_outputVolts[21];}
    Q_PROPERTY(float Output_23_Volts 	READ Output_23_Volts 	NOTIFY onRacepakDataChanged) const float& Output_23_Volts() 	{return m_outputVolts[22];}
    Q_PROPERTY(float Output_24_Volts 	READ Output_24_Volts 	NOTIFY onRacepakDataChanged) const float& Output_24_Volts() 	{return m_outputVolts[23];}
    Q_PROPERTY(float Output_25_Volts 	READ Output_25_Volts 	NOTIFY onRacepakDataChanged) const float& Output_25_Volts() 	{return m_outputVolts[24];}
    Q_PROPERTY(float Output_26_Volts 	READ Output_26_Volts 	NOTIFY onRacepakDataChanged) const float& Output_26_Volts() 	{return m_outputVolts[25];}
    Q_PROPERTY(float Output_27_Volts 	READ Output_27_Volts 	NOTIFY onRacepakDataChanged) const float& Output_27_Volts() 	{return m_outputVolts[26];}
    Q_PROPERTY(float Output_28_Volts 	READ Output_28_Volts 	NOTIFY onRacepakDataChanged) const float& Output_28_Volts() 	{return m_outputVolts[27];}
    Q_PROPERTY(float Output_29_Volts 	READ Output_29_Volts 	NOTIFY onRacepakDataChanged) const float& Output_29_Volts() 	{return m_outputVolts[28];}
    Q_PROPERTY(float Output_30_Volts 	READ Output_30_Volts 	NOTIFY onRacepakDataChanged) const float& Output_30_Volts() 	{return m_outputVolts[29];}
    Q_PROPERTY(unsigned int Output_1_Status 	READ Output_1_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_1_Status() 		{return m_outputStatus[0];}
    Q_PROPERTY(unsigned int Output_2_Status 	READ Output_2_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_2_Status() 		{return m_outputStatus[1];}
    Q_PROPERTY(unsigned int Output_3_Status 	READ Output_3_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_3_Status() 		{return m_outputStatus[2];}
    Q_PROPERTY(unsigned int Output_4_Status 	READ Output_4_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_4_Status() 		{return m_outputStatus[3];}
    Q_PROPERTY(unsigned int Output_5_Status 	READ Output_5_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_5_Status() 		{return m_outputStatus[4];}
    Q_PROPERTY(unsigned int Output_6_Status 	READ Output_6_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_6_Status() 		{return m_outputStatus[5];}
    Q_PROPERTY(unsigned int Output_7_Status 	READ Output_7_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_7_Status() 		{return m_outputStatus[6];}
    Q_PROPERTY(unsigned int Output_8_Status 	READ Output_8_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_8_Status() 		{return m_outputStatus[7];}
    Q_PROPERTY(unsigned int Output_9_Status 	READ Output_9_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_9_Status() 		{return m_outputStatus[8];}
    Q_PROPERTY(unsigned int Output_10_Status 	READ Output_10_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_10_Status() 	{return m_outputStatus[9];}
    Q_PROPERTY(unsigned int Output_11_Status 	READ Output_11_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_11_Status() 	{return m_outputStatus[10];}
    Q_PROPERTY(unsigned int Output_12_Status 	READ Output_12_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_12_Status() 	{return m_outputStatus[11];}
    Q_PROPERTY(unsigned int Output_13_Status 	READ Output_13_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_13_Status() 	{return m_outputStatus[12];}
    Q_PROPERTY(unsigned int Output_14_Status 	READ Output_14_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_14_Status() 	{return m_outputStatus[13];}
    Q_PROPERTY(unsigned int Output_15_Status 	READ Output_15_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_15_Status() 	{return m_outputStatus[14];}
    Q_PROPERTY(unsigned int Output_16_Status 	READ Output_16_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_16_Status() 	{return m_outputStatus[15];}
    Q_PROPERTY(unsigned int Output_17_Status 	READ Output_17_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_17_Status() 	{return m_outputStatus[16];}
    Q_PROPERTY(unsigned int Output_18_Status 	READ Output_18_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_18_Status() 	{return m_outputStatus[17];}
    Q_PROPERTY(unsigned int Output_19_Status 	READ Output_19_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_19_Status() 	{return m_outputStatus[18];}
    Q_PROPERTY(unsigned int Output_20_Status 	READ Output_20_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_20_Status() 	{return m_outputStatus[19];}
    Q_PROPERTY(unsigned int Output_21_Status 	READ Output_21_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_21_Status() 	{return m_outputStatus[20];}
    Q_PROPERTY(unsigned int Output_22_Status 	READ Output_22_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_22_Status() 	{return m_outputStatus[21];}
    Q_PROPERTY(unsigned int Output_23_Status 	READ Output_23_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_23_Status() 	{return m_outputStatus[22];}
    Q_PROPERTY(unsigned int Output_24_Status 	READ Output_24_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_24_Status() 	{return m_outputStatus[23];}
    Q_PROPERTY(unsigned int Output_25_Status 	READ Output_25_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_25_Status() 	{return m_outputStatus[24];}
    Q_PROPERTY(unsigned int Output_26_Status 	READ Output_26_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_26_Status() 	{return m_outputStatus[25];}
    Q_PROPERTY(unsigned int Output_27_Status 	READ Output_27_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_27_Status() 	{return m_outputStatus[26];}
    Q_PROPERTY(unsigned int Output_28_Status 	READ Output_28_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_28_Status() 	{return m_outputStatus[27];}
    Q_PROPERTY(unsigned int Output_29_Status 	READ Output_29_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_29_Status() 	{return m_outputStatus[28];}
    Q_PROPERTY(unsigned int Output_30_Status 	READ Output_30_Status 	NOTIFY onRacepakDataChanged) const unsigned int& Output_30_Status() 	{return m_outputStatus[29];}
    Q_PROPERTY(bool Input_1_Status 		READ Input_1_Status 	NOTIFY onRacepakDataChanged) const bool& Input_1_Status() 		{return m_inputStatus[0];}
    Q_PROPERTY(bool Input_2_Status 		READ Input_2_Status 	NOTIFY onRacepakDataChanged) const bool& Input_2_Status() 		{return m_inputStatus[1];}
    Q_PROPERTY(bool Input_3_Status 		READ Input_3_Status 	NOTIFY onRacepakDataChanged) const bool& Input_3_Status() 		{return m_inputStatus[2];}
    Q_PROPERTY(bool Input_4_Status 		READ Input_4_Status 	NOTIFY onRacepakDataChanged) const bool& Input_4_Status() 		{return m_inputStatus[3];}
    Q_PROPERTY(bool Input_5_Status 		READ Input_5_Status 	NOTIFY onRacepakDataChanged) const bool& Input_5_Status() 		{return m_inputStatus[4];}
    Q_PROPERTY(bool Input_6_Status 		READ Input_6_Status 	NOTIFY onRacepakDataChanged) const bool& Input_6_Status() 		{return m_inputStatus[5];}
    Q_PROPERTY(bool Input_7_Status 		READ Input_7_Status 	NOTIFY onRacepakDataChanged) const bool& Input_7_Status() 		{return m_inputStatus[6];}
    Q_PROPERTY(bool Input_8_Status 		READ Input_8_Status 	NOTIFY onRacepakDataChanged) const bool& Input_8_Status() 		{return m_inputStatus[7];}
    Q_PROPERTY(bool Input_9_Status 		READ Input_9_Status 	NOTIFY onRacepakDataChanged) const bool& Input_9_Status() 		{return m_inputStatus[8];}
    Q_PROPERTY(bool Input_10_Status 	READ Input_10_Status 	NOTIFY onRacepakDataChanged) const bool& Input_10_Status() 		{return m_inputStatus[9];}
    Q_PROPERTY(bool Input_11_Status 	READ Input_11_Status 	NOTIFY onRacepakDataChanged) const bool& Input_11_Status() 		{return m_inputStatus[10];}
    Q_PROPERTY(bool Input_12_Status 	READ Input_12_Status 	NOTIFY onRacepakDataChanged) const bool& Input_12_Status() 		{return m_inputStatus[11];}


};

#endif // RACEPAKCANCONTROL_H
