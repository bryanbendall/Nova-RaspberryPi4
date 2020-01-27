import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    width: 180
    height: childrenRect.height

    property alias name: nameLabel.text
    property real value: 50
    property string suffix
    property int decimalPlaces: 1
    property real lowWarn: -1

    Label{
        id: nameLabel
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        text: "Coolant Temp"
        color: "white"
        font.pointSize: 12
    }
    Label{
        id: valueLabel
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: nameLabel.bottom
        text: value.toFixed(decimalPlaces) + suffix
        color: "white"
        font.pointSize: 20
        background: Rectangle{
            color: value < lowWarn ? "red" : "transparent"
        }
    }

}
