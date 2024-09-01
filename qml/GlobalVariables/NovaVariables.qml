pragma Singleton
import QtQuick 2.0

QtObject{

    //Nova
    property real rpm: holleyCan.RPM
    property real afr: holleyCan.AFR_Left
    property real afr2: holleyCan.AFR_Right
    property bool secondAfr: false
    property real boost: holleyCan.Boost
    property real gasLevel: novaCan.GasLevel
    property real methLevel: novaCan.MethLevel
    property bool methSecondLevel: true
    property real gear: holleyCan.Gear
    property real cts: holleyCan.CTS
    property real oilPressure: holleyCan.Oil_Pressure
    property real battery: holleyCan.Battery
    property real lineTemp: holleyCan.Line_Temp
    property real fuelPressure: holleyCan.Fuel_Pressure
    property real methPressure: holleyCan.Input_7
    property real speed: holleyCan.Speed
    property bool useKph: true
    property real closedLoopComp: holleyCan.CL_Comp
    property bool showOdometer: true

    property bool overDrive: (holleyCan.Output_29 > 0.0)
    property bool parkNeutral: (holleyCan.Input_30 > 0.0)
    property bool fanState: (holleyCan.Fan_1 > 0.0)
    property bool leftTurnState: novaCan.LeftTurn
    property bool rightTurnState: novaCan.RightTurn
    property bool parkingLightState: novaCan.ParkingLights
    property bool lowBeamLightState: novaCan.LowBeam
    property bool highbeamIndicatorState: novaCan.HighBeam
    property bool reverse: novaCan.ReverseLights
    property bool showGear: true
    property bool parkingBrakeState: false

    // Not Used
    property real egt1: 1385.0
    property real egt2: 1385.0
    property real egt3: 1385.0
    property real egt4: 1385.0
    property real egt5: 1385.0
    property real egt6: 1111.0
    property real egt7: 200.0
    property real egt8: 1500.0

}

