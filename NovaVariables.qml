pragma Singleton
import QtQuick 2.0

QtObject{

    //Nova
    property real rpm: holleyCan.RPM
    property real afr: holleyCan.AFR_Left
    property real boost: holleyCan.Boost
    property real gasLevel: holleyCan.Input_11
    property real methLevel: 50
    property real gear: holleyCan.Gear
    property real cts: holleyCan.CTS
    property real oilPressure: holleyCan.Oil_Pressure
    property real battery: holleyCan.Battery
    property real lineTemp: holleyCan.Line_Temp
    property real fuelPressure: holleyCan.Fuel_Pressure
    property real methPressure: holleyCan.Input_7
    property real speed: holleyCan.Speed
    property real closedLoopComp: holleyCan.CL_Comp

    property bool overDrive: holleyCan.Output_29 > 0.0
    property bool parkNeutral: false//holleyCan.Input_30
    property bool fanState: holleyCan.Fan_1 > 0.0
    property bool leftTurnState: false
    property bool rightTurnState: false
    property bool highbeamIndicatorState: false
    property bool showGear: true
    property bool parkingBrakeState: false

}

