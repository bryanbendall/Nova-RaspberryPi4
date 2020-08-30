import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import GlobalVariables 1.0

Item {

    Canvas {
        anchors.left: gauge.left
        anchors.verticalCenter: parent.verticalCenter
        height: gauge.height - 18
        width: gauge.radius + gauge.lineWidth / 2

        onPaint: {
            var ctx = getContext("2d")
            ctx.reset()

            ctx.beginPath()
            ctx.strokeStyle = "#e5e5e5"
            ctx.lineWidth = 3
            ctx.arc(width + 47, height/2, gauge.radius + 22, 0,
                    Math.PI * 2)
            ctx.stroke()

            ctx.beginPath()
            ctx.strokeStyle = "#2D2B2E"
            ctx.lineWidth = 5
            ctx.arc(width + 47, height/2, gauge.radius + 17, 0,
                    Math.PI * 2)
            ctx.stroke()
        }
    }

    Gauge {
        id: gauge
        anchors.left: parent.left
        anchors.leftMargin: 340
        anchors.verticalCenter: parent.verticalCenter
        height: parent.height - 100
        value: GlobalVariables.boost

        property real lineWidth: 20
        property real radius: 250

        minimumValue: 0
        maximumValue: 25
        minorTickmarkCount: 0
        tickmarkStepSize: 5

        style: GaugeStyle {

            valueBar: Canvas {
                width: gauge.radius + gauge.lineWidth / 2
                onPaint: {
                    var ctx = getContext("2d")
                    ctx.reset()

                    ctx.beginPath()
                    ctx.strokeStyle = gauge.value >= 20 ? "#B30C14" : "#5ADA17"
                    ctx.lineWidth = gauge.lineWidth
                    ctx.arc(width, height - (gauge.height / 2) + 9,
                            gauge.radius, 0, Math.PI * 2)
                    ctx.stroke()
                }
            }

            tickmark: Rectangle {
                width: 25
                height: 3
                color: "#e5e5e5"
                x: {
                    var r = Math.pow(gauge.radius + gauge.lineWidth / 2, 2)
                    var h = Math.pow(
                                styleData.valuePosition - (gauge.height / 2) + 9,
                                2)
                    var intermediat = r - h
                    gauge.radius - Math.sqrt(intermediat) + 25
                }
            }

            minorTickmark: Rectangle {
                width: 7
                height: 1
                color: "#e5e5e5"
                x: {
                    var r = Math.pow(gauge.radius + gauge.lineWidth / 2, 2)
                    var h = Math.pow(
                                styleData.valuePosition - (gauge.height / 2) + 9,
                                2)
                    var intermediat = r - h
                    gauge.radius - Math.sqrt(intermediat) + 9
                }
            }

            tickmarkLabel: Text {
                color: styleData.value >= 16 ? "#B30C14" : "#e5e5e5"
                text: styleData.value
                x: {
                    var r = Math.pow(gauge.radius + gauge.lineWidth / 2 + 50, 2)
                    var per = (styleData.value / (gauge.maximumValue
                                                  - gauge.minimumValue)) * gauge.height
                    var h = Math.pow(per - (gauge.height / 2), 2)
                    gauge.radius - Math.sqrt(r - h) + 70
                }
            }
        }
    }
}
