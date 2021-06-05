import QtQuick 2.0
import QtQuick.Controls 2.0
import GlobalColors 1.0

Button {
    property bool led: false

    width: 100
    height: 100
    text: "Button"
    Rectangle{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        radius: 5
        color: led ? GlobalColors.gray : GlobalColors.green
        width: 40
        height: 10
    }
}
