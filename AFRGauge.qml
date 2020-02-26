import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import GlobalVariables 1.0

Item {

    CircularGauge {
        id: guage
        anchors.centerIn: parent
        width: 540
        height: width

        minimumValue: 10
        maximumValue: 16
        value: GlobalVariables.afr

        style: CircularGaugeStyle {
            minimumValueAngle: 50
            maximumValueAngle: 130

            tickmarkStepSize: 2
            tickmarkLabel: Text {
                font.pixelSize: 18
                text: styleData.value
                color: styleData.value <= 10 ? "#B30C14" : styleData.value
                                               >= 16 ? "#B30C14" : "#e5e5e5"
                antialiasing: true
            }

            tickmark: Rectangle {
                width: 3
                height: 20
                antialiasing: true
                color: styleData.value <= 10 ? "#B30C14" : styleData.value
                                               >= 16 ? "#B30C14" : "#e5e5e5"
            }

            labelInset: -20
            minorTickmarkCount: 0

            needle: Image {
                width: 15
                height: 45
                y: -230
                source: "Images/Needle.png"
            }

            function degreesToRadians(degrees) {
                return degrees * (Math.PI / 180)
            }

            background: Canvas {
                onPaint: {
                    var ctx = getContext("2d")
                    ctx.reset()

                    ctx.beginPath()
                    var grad = ctx.createConicalGradient(
                                outerRadius, outerRadius, degreesToRadians(
                                    valueToAngle(guage.maximumValue)))
                    grad.addColorStop(0.57, "#B30C14") // Red
                    grad.addColorStop(0.58, "#e5e5e5") // White
                    grad.addColorStop(0.72, "#e5e5e5") // White
                    grad.addColorStop(0.75, "#B30C14") // Red
                    ctx.strokeStyle = grad
                    ctx.lineWidth = 3
                    ctx.arc(outerRadius, outerRadius,
                            outerRadius - ctx.lineWidth / 2, degreesToRadians(
                                valueToAngle(guage.minimumValue) - 90), degreesToRadians(
                                valueToAngle(guage.maximumValue) - 90))
                    ctx.stroke()
                }
            }
        }
    }

}
