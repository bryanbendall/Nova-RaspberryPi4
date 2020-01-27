import QtQuick 2.0

Text {
    id: mphText
    property real speed: 0
    color: "#e5e5e5"
    font.pointSize: 100
    text: Math.floor(speed)

    Text {
        anchors.top: parent.bottom
        anchors.topMargin: -30
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#e5e5e5"
        font.pointSize: 20
        text: "Mph"
    }

    SequentialAnimation{
        running: true
        NumberAnimation{ target: mphText; property: "speed"; to: 150; duration: 5000; }
        NumberAnimation{ target: mphText; property: "speed"; to: 0; duration: 5000; }
        loops: Animation.Infinite
    }

}
