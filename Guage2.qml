import QtQuick 2.0
import GlobalColors 1.0

Item {

    property real minValue: 0
    property real maxValue: 100
    property real value: 50
    property real highWarn: 10000
    property real lowWarn: -1000
    property bool showLowWarn: true
    property int decialPlaces: 0
    property alias units: unitText.text
    property alias image: symbol.imageSource

    width: 200
    height: width

    onValueChanged: canvas.requestPaint()

    function degreesToRadians(degrees) {
        return degrees * (Math.PI / 180)
    }

    function valueToRadians(value) {
        var tempValue
        if(value < minValue)
            tempValue = minValue
        else if(value > maxValue)
            tempValue = maxValue
        else
            tempValue = value

        var tempDegrees = ((tempValue - minValue) / (maxValue - minValue)) * 270


        return degreesToRadians(tempDegrees + 90)
    }

    Canvas{
        id: canvas
        anchors.fill: parent
        antialiasing: true
        onPaint: {
            var ctx = getContext("2d")

            var barWidth = parent.width * .07

            ctx.beginPath()
            ctx.lineWidth = barWidth
            ctx.strokeStyle = value < lowWarn & showLowWarn ? GlobalColors.red : GlobalColors.gray
            ctx.arc(width/2, height/2, width / 2 - barWidth / 2 , degreesToRadians(90), degreesToRadians(360), false)
            ctx.stroke()

            ctx.beginPath()
            ctx.lineWidth = barWidth
            ctx.strokeStyle = value > highWarn ? GlobalColors.red : GlobalColors.orange
            ctx.arc(width/2, height/2, width / 2 - barWidth / 2 , degreesToRadians(90), valueToRadians(parent.value), false)
            ctx.stroke()
        }
    }

    Text{
        id: valueText
        anchors.centerIn: parent
        text: parent.value.toFixed(parent.decialPlaces)
        color: GlobalColors.white
        font.pointSize: parent.width * .2
    }

    Text{
        id: unitText
        anchors.bottom: valueText.top
        anchors.horizontalCenter: valueText.horizontalCenter
        text: "°F"
        font.pointSize: parent.width * .1
        color: GlobalColors.gray
    }

    ColorVectorImage{
        id: symbol
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: valueText.bottom
        width: parent.width * .2
        height: width
        imageSource: "Images/water-temp.svg"
        color: GlobalColors.gray
    }

    Text{
        id: minText
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -7
        text: parent.minValue.toFixed(parent.decialPlaces)
        color: GlobalColors.gray
        font.pointSize: parent.width * .07
    }

    Text{
        id: maxText
        anchors.top: parent.verticalCenter
        anchors.topMargin: 2
        anchors.horizontalCenter: parent.right
        text: parent.maxValue.toFixed(parent.decialPlaces)
        color: GlobalColors.gray
        font.pointSize: parent.width * .07
    }

}
