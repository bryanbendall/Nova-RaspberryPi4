import QtQuick 2.0
import GlobalVariables 1.0
import "../Components"

Item {
    id: root
    property real guageSize: 130

    Column{
        anchors.right: parent.right
        anchors.rightMargin: 40
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 130
        spacing: 30

        Row{
            spacing: 30
            Guage2{
                width: root.guageSize
                height: root.guageSize
                minValue: 6
                maxValue: 18
                value: GlobalVariables.battery
                highWarn: 16
                lowWarn: 10
                decialPlaces: 1
                units: "V"
                image: "../../Images/battery.svg"
            }
            Guage2{
                width: root.guageSize
                height: root.guageSize
                minValue: 50
                maxValue: 280
                highWarn: 200
                value: GlobalVariables.lineTemp
                units: "°F"
                image: "../../Images/transmission-temp.svg"
            }
        }

        Row{
            spacing: 30
            Guage2{
                width: root.guageSize
                height: root.guageSize
                minValue: 0
                maxValue: 100
                value: GlobalVariables.fuelPressure
                lowWarn: 30
                units: "Gas Psi"
                image: "../../Images/gasicon.svg"
            }
            Guage2{
                width: root.guageSize
                height: root.guageSize
                minValue: 0
                maxValue: 100
                value: GlobalVariables.methPressure
                lowWarn: 30
                showLowWarn: false
                units: "Meth Psi"
                image: "../../Images/gasicon.svg"
            }
        }





    }

}
