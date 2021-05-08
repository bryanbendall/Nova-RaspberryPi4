import QtQuick 2.7
import QtQuick.Controls 2.0
import GlobalVariables 1.0
import GlobalColors 1.0

Item {
    //property real scalling: 2.1333

    //To Fix Screen Size
    //transform: Scale{
        //origin.x: 0
        //origin.y: 0
        //xScale: 1
        //yScale: scalling
    //}

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

        Row{
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 10
            width: 500
            leftPadding: 120
            spacing: 20

            ColorVectorImage{
                width: 50
                height: 50
                imageSource: "Images/parking-brake.svg"
                color: GlobalColors.red
                visible: GlobalVariables.parkingBrakeState
            }

            ColorVectorImage{
                width: 50
                height: 50
                imageSource: "Images/high-beam.svg"
                color: GlobalColors.blue
                visible: GlobalVariables.highbeamIndicatorState
            }
        }

        ColorVectorImage{
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 130
            width: 50
            height: 50
            imageSource: "Images/turn-signal.svg"
            color: GlobalColors.green
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
            color: GlobalColors.green
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
            anchors.leftMargin: 100
            spacing: 20
            Guage2{
                id: tempGauge
                width: 160
                height: 160
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
                    color: GlobalColors.blue
                    visible: GlobalVariables.fanState
                }
            }

            Guage2{
                id: oilGauge
                width: 160
                height: 160
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

        ClosedLoopGauge{
            anchors.fill: parent
        }

        Text{
            anchors.right: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.rightMargin: 170
            anchors.bottomMargin: 20
            color: GlobalColors.gray
            font.pointSize: 12
            text: "Boost"
        }

        Text{
            anchors.left: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.leftMargin: 200
            anchors.bottomMargin: 20
            color: GlobalColors.gray
            font.pointSize: 12
            text: "CL%"
        }

        TachGuage{
            id: tach
            anchors.centerIn: parent
        }

        Row{
            id: afrRow
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 140
            spacing: 15

            Text{
                id: afr1
                property real val: 12.1
                font.pointSize: 30
                text: GlobalVariables.afr.toFixed(1)
                color: GlobalVariables.afr > 16 | GlobalVariables.afr < 10 ? GlobalColors.red : GlobalColors.white
            }
            Text{
                visible: GlobalVariables.secondAfr
                font.pointSize: 30
                text: GlobalVariables.afr2.toFixed(1)
                color: GlobalVariables.afr > 16 | GlobalVariables.afr < 10 ? GlobalColors.red : GlobalColors.white
            }
        }
        Text{
            anchors.bottom: afrRow.top
            anchors.bottomMargin: -5
            anchors.horizontalCenter: afrRow.horizontalCenter
            color: GlobalColors.gray
            font.pointSize: 14
            text: "AFR"
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
