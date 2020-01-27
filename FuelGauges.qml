import QtQuick 2.0

Item {
    id: root

    property real gasValue: 73
    property real methValue: 25

    SequentialAnimation{
            running: true
        NumberAnimation{ target: root; property: "gasValue"; to: 100; duration: 3000; }
        NumberAnimation{ target: root; property: "gasValue"; to: 0; duration: 3000; }
        loops: Animation.Infinite
    }

    SequentialAnimation{
            running: true
        NumberAnimation{ target: root; property: "methValue"; to: 100; duration: 3000; }
        NumberAnimation{ target: root; property: "methValue"; to: 0; duration: 3000; }
        loops: Animation.Infinite
    }

    ColorVectorImage{
        id: methIcon
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 32
        height: 32
        color: "#e5e5e5"
        imageSource: "Images/gasicon.svg"
        Text{
            anchors.right: parent.right
            anchors.rightMargin: 14
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 2
            color: "black"
            text: "M"
            font.pointSize: 10
        }
    }
    Rectangle {
        anchors.left: methIcon.right
        anchors.right: parent.right
        anchors.leftMargin: 10
        anchors.verticalCenter: methIcon.verticalCenter
        color: "#2D2B2E"
        height: 10
        Rectangle{
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height
            width: parent.width * (root.methValue / 100)
            color: "#FD9012"
        }
    }

    ColorVectorImage{
        id: gasIcon
        anchors.left: parent.left
        anchors.bottom: methIcon.top
        width: 32
        height: 32
        color: "#e5e5e5"
        imageSource: "Images/gasicon.svg"
    }
    Rectangle {
        anchors.left: gasIcon.right
        anchors.right: parent.right
        anchors.leftMargin: 10
        anchors.verticalCenter: gasIcon.verticalCenter
        color: "#2D2B2E"
        height: 10
        Rectangle{
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height
            width: parent.width * (root.gasValue / 100)
            color: "#FD9012"
        }
    }

}
