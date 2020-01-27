import QtQuick 2.0
import QtQuick.Controls 2.0

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

        ColorVectorImage{
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 130
            width: 50
            height: 50
            imageSource: "Images/turn-signal.svg"
            color: "#4CD90F"
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
                value: 180
                units: "°F"
                image: "Images/water-temp.svg"
                ColorVectorImage{
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    width: 50
                    height: 50
                    imageSource: "Images/fan.svg"
                    color: "#0F829D"
                }
                SequentialAnimation{
                        running: true
                    NumberAnimation{ target: tempGauge; property: "value"; to: 250; duration: 3000; }
                    NumberAnimation{ target: tempGauge; property: "value"; to: 30; duration: 3000; }
                    loops: Animation.Infinite
                }
            }
            Guage2{
                id: oilGauge
                minValue: 0
                maxValue: 100
                value: 40
                units: "PSI"
                image: "Images/engine-oil.svg"
            }
            SequentialAnimation{
                    running: true
                NumberAnimation{ target: oilGauge; property: "value"; to: 100; duration: 3000; }
                NumberAnimation{ target: oilGauge; property: "value"; to: 0; duration: 3000; }
                loops: Animation.Infinite
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
