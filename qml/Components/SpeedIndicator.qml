import QtQuick 2.0
import GlobalVariables 1.0
import GlobalColors 1.0

Text {
    color: GlobalColors.white
    font.pointSize: 80
    text: GlobalVariables.useKph ? Math.floor(GlobalVariables.speed * 1.609344) : Math.floor(GlobalVariables.speed)

    Text {
        anchors.top: parent.bottom
        anchors.topMargin: -25
        anchors.horizontalCenter: parent.horizontalCenter
        color: GlobalColors.gray
        font.pointSize: 20
        text: GlobalVariables.useKph ? "Kph" : "Mph"
    }

}
