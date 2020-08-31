import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import GlobalVariables 1.0
import GlobalColors 1.0

Item {

    CircularGauge {
        id: guage
        anchors.centerIn: parent
        width: 540
        height: width

        minimumValue: -50
        maximumValue: 50
        value: GlobalVariables.closedLoopComp

        style: CircularGaugeStyle {
            minimumValueAngle: 130
            maximumValueAngle: 50

            tickmarkStepSize: 25
            tickmarkLabel: Text {
                font.pixelSize: 18
                text: styleData.value
                color: GlobalColors.white
                antialiasing: true
            }

            tickmark: Rectangle {
                width: 3
                height: 20
                antialiasing: true
                color: GlobalColors.white
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
                    ctx.strokeStyle = GlobalColors.white
                    ctx.lineWidth = 3
                    ctx.arc(outerRadius, outerRadius,
                            outerRadius - ctx.lineWidth / 2,
                            degreesToRadians(valueToAngle(guage.maximumValue) - 90),
                            degreesToRadians(valueToAngle(guage.minimumValue) - 90))
                    ctx.stroke()
                }
            }
        }
    }

}
