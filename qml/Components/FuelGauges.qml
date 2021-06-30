import QtQuick 2.0
import GlobalVariables 1.0
import GlobalColors 1.0

Item {
    id: root

    property real gasValue: GlobalVariables.gasLevel
    property real methValue: GlobalVariables.methSecondLevel ? GlobalVariables.methLevel : GlobalVariables.gasLevel2

    ColorVectorImage{
        id: methIcon
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 32
        height: 32
        color: root.methValue < 20 ? GlobalColors.red : GlobalColors.white
        imageSource: "../../Images/gasicon.svg"
        Text{
            visible: GlobalVariables.methSecondLevel
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
        color: root.methValue < 20 ? GlobalColors.red : GlobalColors.gray
        height: 10
        Rectangle{
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height
            width: parent.width * (root.methValue / 100)
            color: GlobalColors.orange
        }
    }

    ColorVectorImage{
        id: gasIcon
        anchors.left: parent.left
        anchors.bottom: methIcon.top
        width: 32
        height: 32
        color: root.gasValue < 20 ? GlobalColors.red : GlobalColors.white
        imageSource: "../../Images/gasicon.svg"
    }
    Rectangle {
        anchors.left: gasIcon.right
        anchors.right: parent.right
        anchors.leftMargin: 10
        anchors.verticalCenter: gasIcon.verticalCenter
        color: root.gasValue < 20 ? GlobalColors.red : GlobalColors.gray
        height: 10
        Rectangle{
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height
            width: parent.width * (root.gasValue / 100)
            color: GlobalColors.orange
        }
    }

}
