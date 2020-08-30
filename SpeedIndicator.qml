import QtQuick 2.0
import GlobalVariables 1.0

Text {
    id: mphText
    property real speed: GlobalVariables.speed
    color: "#e5e5e5"
    font.pointSize: 100
    text: Math.floor(speed * 1.609344)

    Text {
        anchors.top: parent.bottom
        anchors.topMargin: -30
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#e5e5e5"
        font.pointSize: 20
        text: "Kph"
    }

}
