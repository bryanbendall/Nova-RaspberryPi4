import QtQuick 2.7
import QtQuick.Controls 2.0
import GlobalVariables 1.0
import GlobalColors 1.0
import "../Components"
import "../Panels"

Item {
    //property real scalling: 2.1333

    //To Fix Screen Size
    //transform: Scale{
        //origin.x: 0
        //origin.y: 0
        //xScale: 1
        //yScale: scalling
    //}

    Rectangle{
        width: parent.width
        height: 480
        color: "black"

        RightPanel{
            anchors.right: parent.right
            anchors.top: parent.top
        }

        IndicatorPanel{
            anchors.top: parent.top
            anchors.left: parent.left
        }

        LeftPanel{
            anchors.left: parent.left
            anchors.bottom: parent.bottom
        }

        TachPanel{
            anchors.centerIn: parent
        }

        FuelPanel{
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }

    }

}
