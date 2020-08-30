import QtQuick 2.0
import GlobalVariables 1.0

Text {
    id: gearText
    property int gearNum: GlobalVariables.odIndicator ? 5 : GlobalVariables.gear
    color: "#FD9012"
    font.pointSize: 80
    text: gearNum
    visible: GlobalVariables.showGear

    Text {
        anchors.top: parent.bottom
        anchors.topMargin: -30
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#FD9012"
        font.pointSize: 14
        text: "Gear"
    }

}
