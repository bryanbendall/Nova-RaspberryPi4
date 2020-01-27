import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    anchors.fill: parent

    Component.onCompleted: {
        canControl.startCan()
    }

    Row{
        id: guageRow
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        height: 300
        anchors.topMargin: 80
        spacing: 120

        Guage{
            label: "AFR"
            value: canControl.afrLeft
            valueMin: 8.5
            valueMax: 20.5
            highWarn: 16
            MouseArea{
                anchors.fill: parent
                onClicked: btControl.start()
            }
        }

        Guage{
            label: "Boost"
            value: (canControl.map * 0.145038) - 14.5038
            valueMin: 0
            valueMax: 25
        }

    }

    Label{
        id: gearName
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 50
        color: "white"
        text: "Gear"
        font.pointSize: 16
    }
    Label{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: gearName.bottom
        anchors.topMargin: -20
        color: "white"
        text: canControl.gear
        font.pointSize: 80
    }

    Row{
        id: labelRow1
        anchors.top: guageRow.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        TextGuage{
            name: "Coolant Temp"
            value: canControl.cts
            suffix: " °F"
            decimalPlaces: 0
        }
        TextGuage{
            name: "Oil Pressure"
            value: canControl.oilPress
            suffix: " psi"
            decimalPlaces: 0
            lowWarn: 1
        }
        TextGuage{
            name: "Fuel Pressure"
            value: canControl.fuelPress
            suffix: " psi"
            decimalPlaces: 0
            lowWarn: 20
        }
        TextGuage{
            name: "MPG"
            value: canControl.speed < 2 ? 0 : (canControl.speed / (canControl.fuelFlow * 0.1408))
        }
    }

    Row{
        id: labelRow2
        anchors.top: labelRow1.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 50

        TextGuage{
            name: "Line Temp"
            value: canControl.lineTemp
            suffix: " °F"
            decimalPlaces: 0
        }
        TextGuage{
            name: "Voltage"
            value: canControl.batteryVolt
            lowWarn: 10
        }
        TextGuage{
            name: "MAT"
            value: canControl.mat
            suffix: " °F"
            decimalPlaces: 0
        }
        TextGuage{
            id: speedGuage
            name: "Speed"
            value: canControl.speed * 1.60934
            suffix: " kph"
            decimalPlaces: 0
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(speedGuage.suffix == " kph"){
                        speedGuage.suffix = " mph"
                        speedGuage.value = Qt.binding(canControl.speed)
                    } else {
                        speedGuage.suffix = " kph"
                        speedGuage.value = (Qt.binding(canControl.speed) * 1.60934)
                    }
                }
            }
        }
    }

    SerialButtons{
        anchors.top: labelRow2.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
    }



}
