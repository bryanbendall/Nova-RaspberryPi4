import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    width: 300
    height: 300

    property int barWidth: 30
    property real value: 50
    property real valueMin: 0
    property real valueMax: 100
    property alias label: guageLabel.text
    property string suffix
    property int decimalPlaces: 1
    property real lowWarn: -1
    property real highWarn: 101
    property alias fontSize: valueLabel.font.pointSize

    onValueChanged: {
        canvas.requestPaint()
    }

    Canvas{
        id: canvas
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d")

            ctx.beginPath()
            ctx.lineWidth = barWidth
            ctx.strokeStyle = '#111111'
            ctx.arc(width/2, height/2, width / 2 - barWidth / 2 , 2.44, 0.70, false)
            ctx.stroke()

            ctx.beginPath()
            ctx.lineWidth = barWidth - 2
            ctx.strokeStyle = '#5294e2'
//            ctx.arc(width/2, height/2, width / 2 - barWidth / 2 , 2.44, toRadians(valueToDegrees()), false)
            ctx.arc(width/2, height/2, width / 2 - barWidth / 2 , 2.44, valueToDegrees() * (Math.PI / 180), false)
            ctx.stroke()
        }
    }

    Label{
        id: guageLabel
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: valueLabel.top
        color: "white"
        font.pointSize: 20
    }
    Label{
        id: valueLabel
        anchors.centerIn: parent
        color: "white"
        font.pointSize: 50
        text: value.toFixed(decimalPlaces) + suffix
        background: Rectangle{
            color: value < lowWarn ? "red" : value > highWarn ? "red" : "transparent"
        }
    }

//    function toRadians (angle) {
//      return angle * (Math.PI / 180);
//    }

    function valueToDegrees(){
        if(value < valueMin){
            return 140
        }

        if(value > valueMax){
            return 40
        }

        var v = ((value - valueMin) / (valueMax - valueMin) * 260) + 140
        if(v > 360){
            v = ((value - valueMin) / (valueMax - valueMin) * 260) - 220
        }
        return v
    }

}
