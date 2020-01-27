import QtQuick 2.0

Item {

    property real minValue: 0
    property real maxValue: 100
    property real value: 50
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
            ctx.strokeStyle = '#2D2B2E'
            ctx.arc(width/2, height/2, width / 2 - barWidth / 2 , degreesToRadians(90), degreesToRadians(360), false)
            ctx.stroke()

            ctx.beginPath()
            ctx.lineWidth = barWidth - 2
            ctx.strokeStyle = '#FD9012'
            ctx.arc(width/2, height/2, width / 2 - barWidth / 2 , degreesToRadians(90), valueToRadians(parent.value), false)
            ctx.stroke()
        }
    }

    Text{
        id: valueText
        anchors.centerIn: parent
        text: parent.value.toFixed(parent.decialPlaces)
        color: "#e5e5e5"
        font.pointSize: parent.width * .2
    }

    Text{
        id: unitText
        anchors.bottom: valueText.top
        anchors.horizontalCenter: valueText.horizontalCenter
        text: "°F"
        font.pointSize: parent.width * .1
        color: "#6D6D6D"
    }

    ColorVectorImage{
        id: symbol
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: valueText.bottom
        width: parent.width * .2
        height: width
        imageSource: "Images/water-temp.svg"
        color: "#6D6D6D"
    }

    Text{
        id: minText
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -7
        text: parent.minValue.toFixed(parent.decialPlaces)
        color: "#6D6D6D"
        font.pointSize: parent.width * .07
    }

    Text{
        id: maxText
        anchors.top: parent.verticalCenter
        anchors.topMargin: 2
        anchors.horizontalCenter: parent.right
        text: parent.maxValue.toFixed(parent.decialPlaces)
        color: "#6D6D6D"
        font.pointSize: parent.width * .07
    }

}
