pragma Singleton
import QtQuick 2.0

QtObject{

    //Nova
    property real rpm: holleyCan.RPM
    property real afr: holleyCan.AFR_Left
    property real boost: holleyCan.AFR_Left
    property real gasLevel: 50
    property real methLevel: 50
    property real gear: holleyCan.Gear
    property real cts: holleyCan.CTS
    property real oilPressure: holleyCan.Oil_Pressure
    property real battery: holleyCan.Battery
    property real lineTemp: holleyCan.Line_Temp
    property real fuelPressure: holleyCan.Fuel_Pressure
    property real methPressure: holleyCan.Input_7
    property real speed: holleyCan.Speed

    property bool fanState: racepakCan.Output_1_Amps > 5
    property bool leftTurnState: false
    property bool rightTurnState: false
    property bool highbeamIndicatorState: false
    property bool showGear: false
    property bool parkingBrakeState: false

}

