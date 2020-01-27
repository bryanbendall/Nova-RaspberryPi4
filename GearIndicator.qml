import QtQuick 2.0

Text {
    id: gearText
    property int gearNum: 0
    color: "#FD9012"
    font.pointSize: 80
    text: gearNum

    Text {
        anchors.top: parent.bottom
        anchors.topMargin: -30
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#FD9012"
        font.pointSize: 14
        text: "Gear"
    }

    SequentialAnimation{
        running: true
        NumberAnimation{ target: gearText; property: "gearNum"; to: 5; duration: 5000; }
        NumberAnimation{ target: gearText; property: "gearNum"; to: 0; duration: 5000; }
        loops: Animation.Infinite
    }
}
