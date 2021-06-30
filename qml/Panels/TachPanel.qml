import QtQuick 2.0
import GlobalVariables 1.0
import GlobalColors 1.0
import "../Components"

Item {
    height: 480
    width: 600

    BoostGuage{
        anchors.centerIn: parent
        width: 1280
        height: 480
    }

    ClosedLoopGauge{
        anchors.fill: parent
    }

    Text{
        anchors.right: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.rightMargin: 170
        anchors.bottomMargin: 20
        color: GlobalColors.gray
        font.pointSize: 12
        text: "Boost"
    }

    Text{
        anchors.left: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.leftMargin: 200
        anchors.bottomMargin: 20
        color: GlobalColors.gray
        font.pointSize: 12
        text: "CL%"
    }

    TachGuage{
        id: tach
        anchors.centerIn: parent
    }

    Row{
        id: afrRow
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 140
        spacing: 15

        Text{
            id: afr1
            property real val: 12.1
            font.pointSize: 30
            text: GlobalVariables.afr.toFixed(1)
            color: GlobalVariables.afr > 16 | GlobalVariables.afr < 10 ? GlobalColors.red : GlobalColors.white
        }
        Text{
            visible: GlobalVariables.secondAfr
            font.pointSize: 30
            text: GlobalVariables.afr2.toFixed(1)
            color: GlobalVariables.afr > 16 | GlobalVariables.afr < 10 ? GlobalColors.red : GlobalColors.white
        }
    }
    Text{
        anchors.bottom: afrRow.top
        anchors.bottomMargin: -5
        anchors.horizontalCenter: afrRow.horizontalCenter
        color: GlobalColors.gray
        font.pointSize: 14
        text: "AFR"
    }

    SpeedIndicator{
        anchors.centerIn: parent
    }

    GearIndicator{
        anchors.right: tach.right
        anchors.rightMargin: 50
        anchors.bottom: tach.bottom
    }

    OdometerIndicator{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -30
    }

    ColorVectorImage{
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 130
        width: 50
        height: 50
        imageSource: "../../Images/turn-signal.svg"
        color: GlobalColors.green
        visible: GlobalVariables.rightTurnState
    }

    ColorVectorImage{
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 130
        width: 50
        height: 50
        imageSource: "../../Images/turn-signal.svg"
        color: GlobalColors.green
        visible: GlobalVariables.leftTurnState
        transform: Rotation{
            angle: 180
            origin.x: 25
            origin.y: 25
        }
    }

}
