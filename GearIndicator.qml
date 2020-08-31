import QtQuick 2.0
import GlobalVariables 1.0
import GlobalColors 1.0

Text {
    id: gearText
    property string gearNum: GlobalVariables.parkNeutral ? "P/N" : GlobalVariables.odIndicator ? 5 : GlobalVariables.gear.toFixed(0)
    color: GlobalColors.orange
    font.pointSize: GlobalVariables.parkNeutral ? 45 : 70
    text: gearNum
    visible: GlobalVariables.showGear
    height: 130
    verticalAlignment: Text.AlignVCenter

    Text {
        anchors.top: parent.bottom
        anchors.topMargin: -30
        anchors.horizontalCenter: parent.horizontalCenter
        color: GlobalColors.orange
        font.pointSize: 14
        text: "Gear"
    }

}
