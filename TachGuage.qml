import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import GlobalVariables 1.0

Item {
    height: 450
    width: height

    property int barWidth: 80

    CircularGauge {
        id: guage
        anchors.fill: parent
        minimumValue: 0
        maximumValue: 9000
        value: GlobalVariables.rpm

        style: CircularGaugeStyle {
            needle: Image{
                y: -120
                source: "Images/Needle.png"
            }

            minorTickmarkCount: 3
            minorTickmarkInset: 20
            minorTickmark: Rectangle{
                width: 2
                height: 40
                gradient: Gradient {
                        GradientStop { position: 0.0; color: Qt.rgba(0.2, 0.2, 0.2, 0.5) }
                        GradientStop { position: 1.0; color: "transparent" }
                    }
                Image{
                    source: styleData.value / 250 % 2 ? "" : "Images/Tickmark-Alternate.png"
                    x: -10
                    y: -14
                }
            }

            foreground: null
            minimumValueAngle: -160
            maximumValueAngle: 90

            labelStepSize: 1000
            labelInset: 70
            tickmarkLabel: Text {
                font.pixelSize: 40
                text: styleData.value >= 1 ? styleData.value / 1000 : null
                color: styleData.value >= 8000 ? "#B30C14" : "#e5e5e5"
                antialiasing: true
            }

            tickmarkStepSize: 1000
            tickmarkInset: 5
            tickmark: Image{
                source: styleData.value >= 8000 ? "Images/Tickmark-Red.png" : "Images/Tickmark.png"
            }

            function degreesToRadians(degrees) {
                return degrees * (Math.PI / 180)
            }

            background: Canvas {
                id: guageBackground
                property int value: guage.value
                onValueChanged: requestPaint()
                onPaint: {
                    var ctx = getContext("2d")
                    ctx.reset()

                    ctx.beginPath()
                    ctx.strokeStyle = "black"
                    ctx.lineWidth = outerRadius
                    ctx.arc(outerRadius, outerRadius,
                            outerRadius - ctx.lineWidth / 2, degreesToRadians(0), degreesToRadians(360))
                    ctx.stroke()

                    ctx.beginPath()
                    ctx.strokeStyle = "#FD9012" // Orange
                    ctx.lineWidth = outerRadius * 0.035
                    ctx.arc(outerRadius, outerRadius,
                            outerRadius - ctx.lineWidth / 2 - 8, degreesToRadians(
                                valueToAngle(0) - 90), degreesToRadians(
                                valueToAngle(9000) - 90))
                    ctx.stroke()

                    ctx.beginPath()
                    var grad = ctx.createConicalGradient(outerRadius, outerRadius, degreesToRadians(valueToAngle(9000) - 95))
                    grad.addColorStop(0.0, "#B30C14") // Red
                    grad.addColorStop(0.08, "#B30C14") // Red
                    grad.addColorStop(0.15, "#e5e5e5") // White
                    grad.addColorStop(1.0, "#e5e5e5") // White
                    ctx.strokeStyle = grad
                    ctx.lineWidth = 3
                    ctx.arc(outerRadius, outerRadius,
                            outerRadius - ctx.lineWidth / 2, degreesToRadians(
                                valueToAngle(0) - 92), degreesToRadians(
                                valueToAngle(9000) - 88))
                    ctx.stroke()

//                    ctx.beginPath()
//                    var grad2 = ctx.createRadialGradient(outerRadius, outerRadius, 200, outerRadius, outerRadius, 100)
//                    grad2.addColorStop(0.7, "black")
//                    grad2.addColorStop(0.6, value >=8000 ? "#B30C14" : "#FD9012") // Orange
//                    grad2.addColorStop(0.5, "black")
//                    ctx.strokeStyle = grad2
//                    ctx.lineWidth = outerRadius //* 0.1
//                    ctx.arc(outerRadius, outerRadius,
//                            outerRadius - ctx.lineWidth / 2 - 20, degreesToRadians(
//                                valueToAngle(0) - 90), degreesToRadians(
//                                valueToAngle(guage.value) - 90))
//                    ctx.stroke()

                }
            }
        }
    }

    Column{
        anchors.top: parent.verticalCenter
        anchors.topMargin: 20
        anchors.right: parent.right
        width: 50
        Text{
            color: "#e5e5e5"
            text: Math.floor(guage.value)
            font.pointSize: 14
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text{
            color: "#e5e5e5"
            text: "RPM"
            font.pointSize: 10
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text{
            color: "#e5e5e5"
            text: "1/1000"
            font.pointSize: 10
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }




}
