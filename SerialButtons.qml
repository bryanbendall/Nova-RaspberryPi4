import QtQuick 2.0
import QtQuick.Controls 2.0

Item {

    anchors.topMargin: 40

        Column{
            anchors.fill: parent
            spacing: 30

            Label{
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 50
                text: "Nova"
            }

            Button{
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Lights\n Off"
                width: 100
                height: 100
                onClicked: lightControl.setOff()
            }

            Row{
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 20

                IndicatorButton{
                    text: "Parking"
                    onClicked: lightControl.setParking()
                    led: lightControl.parking
                }
                IndicatorButton{
                    text: "Low Beam"
                    onClicked: lightControl.setLowBeam()
                    led: lightControl.lowBeam
                }
                IndicatorButton{
                    text: "High Beam"
                    onClicked: lightControl.setHighBeam()
                    led: lightControl.highBeam
                }
                IndicatorButton{
                    text: "Driving\n Lights"
                    onClicked: lightControl.setRunning()
                    led: lightControl.running
                }
                IndicatorButton{
                    text: "Interior\n Light"
                    onClicked: lightControl.setInterior()
                    led: lightControl.interior
                }
            }

            Row{
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 100

                Column{
                    spacing: 20
                    Button{
                        text: "Window\n Up"
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 100
                        height: 100
                        onPressed: windowControl.driverUp(true)
                        onReleased: windowControl.driverUp(false)
                    }
                    Label{
                        text: "Driver"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Button{
                        text: "Window\n Down"
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 100
                        height: 100
                        onPressed: windowControl.driverDown(true)
                        onReleased: windowControl.driverDown(false)
                    }
                }

                Column{
                    spacing: 20
                    Button{
                        text: "Window\n Up"
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 100
                        height: 100
                        onPressed: windowControl.passUp(true)
                        onReleased: windowControl.passUp(false)
                    }
                    Label{
                        text: "Passanger"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Button{
                        text: "Window\n Down"
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 100
                        height: 100
                        onPressed: windowControl.passDown(true)
                        onReleased: windowControl.passDown(false)
                    }
                }

            }
        }

}
