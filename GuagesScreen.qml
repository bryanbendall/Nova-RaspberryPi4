import QtQuick 2.0
import QtQuick.Controls 2.0
import GlobalVariables 1.0

Item {
    property real scalling: 2.1333

    //To Fix Screen Size
    transform: Scale{
        origin.x: 0
        origin.y: 0
        xScale: 1
        yScale: scalling
    }

    Rectangle{
        width: parent.width
        height: 480
        color: "black"

        InfoPanel{
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: tach.right
        }

        ColorVectorImage{
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 130
            width: 50
            height: 50
            imageSource: "Images/turn-signal.svg"
            color: "#4CD90F"
            visible: GlobalVariables.rightTurnState
        }

        ColorVectorImage{
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 130
            width: 50
            height: 50
            imageSource: "Images/turn-signal.svg"
            color: "#4CD90F"
            visible: GlobalVariables.leftTurnState
            transform: Rotation{
                angle: 180
                origin.x: 25
                origin.y: 25
            }
        }

        Column{
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 80
            spacing: 20
            Guage2{
                id: tempGauge
                minValue: 30
                maxValue: 250
                value: GlobalVariables.cts
                highWarn: 200
                units: "°F"
                image: "Images/water-temp.svg"
                ColorVectorImage{
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    width: 50
                    height: 50
                    imageSource: "Images/fan.svg"
                    color: "#146AA1"
                    visible: GlobalVariables.fanState
                }
            }
            Guage2{
                id: oilGauge
                minValue: 0
                maxValue: 100
                value: GlobalVariables.oilPressure
                lowWarn: 5
                units: "PSI"
                image: "Images/engine-oil.svg"
            }
        }

        BoostGuage{
            anchors.fill: parent
        }

        AFRGauge{
            anchors.fill: parent
        }

        Text{
            anchors.right: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.rightMargin: 170
            anchors.bottomMargin: 20
            color: "#e5e5e5"
            font.pointSize: 12
            text: "Boost"
        }

        Text{
            anchors.left: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.leftMargin: 200
            anchors.bottomMargin: 20
            color: "#e5e5e5"
            font.pointSize: 12
            text: "AFR"
        }

        TachGuage{
            id: tach
            anchors.centerIn: parent
        }

        ColorVectorImage{
            id: highbeamIndicator
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.bottom: parent.verticalCenter
            anchors.bottomMargin: 70
            width: 50
            height: 50
            imageSource: "Images/high-beam.svg"
            color: "#146AA1"
            visible: GlobalVariables.highbeamIndicatorState
        }

        ColorVectorImage{
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.bottom: parent.verticalCenter
            anchors.bottomMargin: 70
            width: 50
            height: 50
            imageSource: "Images/parking-brake.svg"
            color: "#B30C14"
            visible: GlobalVariables.parkingBrakeState
        }

        SpeedIndicator{
            anchors.centerIn: parent
        }

        GearIndicator{
            anchors.right: tach.right
            anchors.rightMargin: 50
            anchors.bottom: tach.bottom
        }

        OdometerIndicator{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -30
        }

        FuelGauges{
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 30
            anchors.bottomMargin: 20
            width: 300
            height: 100
        }

    }


}
