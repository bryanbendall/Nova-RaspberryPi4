pragma Singleton
import QtQuick 2.0

QtObject{

    // Camaro
    property real rpm: holleyCan.RPM
    property real afr: holleyCan.AFR_Left
    property real afr2: holleyCan.AFR_Right
    property bool secondAfr: true
    property real boost: holleyCan.Boost_PSIG
    property real gasLevel: holleyCan.Input_36 //Right cell
    property real gasLevel2: holleyCan.Input_12 //Left cell
    property bool methSecondLevel: false
    property real methLevel: holleyCan.Input_3
    property real gear: holleyCan.Input_41              ///////////////////////// Need to scale
    property real cts: holleyCan.CTS
    property real oilPressure: holleyCan.Oil_Pressure
    property real battery: holleyCan.Battery
    property real lineTemp: holleyCan.Input_9
    property real fuelPressure: holleyCan.Fuel_Pressure
    property real methPressure: holleyCan.Input_2
    property real speed: holleyCan.Input_7 //holleyCan.Input_6 ************* Using Front wheel speed****************************
    property bool useKph: false
    property real closedLoopComp: holleyCan.CL_Comp
    property bool showOdometer: false

    property bool overDrive: racepakCan.Output_13_Volts > 6.0
    property bool parkNeutral: false
    property bool fanState: false //racepakCan.Output_30_Volts > 6.0
    property bool leftTurnState: racepakCan.Module_Input_2_Status //racepakCan.Output_17_Volts > 6.0
    property bool rightTurnState: racepakCan.Module_Input_1_Status //racepakCan.Output_12_Volts > 6.0
    property bool parkingLightState: false
    property bool lowBeamLightState: racepakCan.Module_Input_4_Status //false
    property bool highbeamIndicatorState: racepakCan.Module_Input_5_Status //racepakCan.Output_8_Volts > 6.0
    property bool reverse: racepakCan.Output_16_Volts > 6.0
    property bool showGear: false
    property bool parkingBrakeState: false

    // Extra Outputs
    property real transFanAmps: racepakCan.Output_1_Amps
    property real waterPumpAmps: racepakCan.Output_5_Amps
    property real scavagePumpAmps: racepakCan.Output_6_Amps
    property real fuelPumpAmps: racepakCan.Output_4_Amps

    // Extra Inputs
    property real panVaccum: holleyCan.Input_1
    property real backPressureLeft: holleyCan.Input_4
    property real backPressureRight: holleyCan.Input_5
    property real frontWheelSpeed: holleyCan.Input_7
    property real oilTemp: holleyCan.Input_8
    property real transPressure: holleyCan.Input_10
    property real converterPressure: holleyCan.Input_11
    property real leftRearShock: holleyCan.Input_13
    property real rightRearShock: holleyCan.Input_14
    property real leftFrontShock: holleyCan.Input_15
    property real rightFrontShock: holleyCan.Input_16
    property real coolantPressure: holleyCan.Input_17
    property real domePressure: holleyCan.Input_18
    property real gMeterX: holleyCan.Input_19
    property real gMeterY: holleyCan.Input_20
    property real egt1: holleyCan.Input_21
    property real egt2: holleyCan.Input_22
    property real egt3: holleyCan.Input_23
    property real egt4: holleyCan.Input_24
    property real egt5: holleyCan.Input_25
    property real egt6: holleyCan.Input_26
    property real egt7: holleyCan.Input_27
    property real egt8: holleyCan.Input_28
    property real leftWGPostition: holleyCan.Input_37
    property real rightWGPostition: holleyCan.Input_38
    property real brakeInput: holleyCan.Input_39
    property real lineLockInput: holleyCan.Input_40
    property real converterTemp: holleyCan.Input_42
    property real driveshaftRPM: holleyCan.Input_44
    property real missfire1: holleyCan.Input_50
    property real missfire2: holleyCan.Input_51
    property real missfire3: holleyCan.Input_52
    property real missfire4: holleyCan.Input_53
    property real missfire5: holleyCan.Input_54
    property real missfire6: holleyCan.Input_55
    property real missfire7: holleyCan.Input_56
    property real missfire8: holleyCan.Input_57

}

