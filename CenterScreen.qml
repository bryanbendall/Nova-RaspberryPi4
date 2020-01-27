import QtQuick 2.0

Item {
    transform: Rotation{
        origin.x: width/2
        origin.y: height/2
        angle: 90
    }

    Rectangle{
        anchors.centerIn: parent
        width: parent.height
        height: parent.width
        color: "blue"

        Text{
            anchors.centerIn: parent
            text: "Center Screen"
            color: "black"
            font.pointSize: 50
        }

    }
}
