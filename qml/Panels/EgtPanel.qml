import QtQuick 2.7
import GlobalVariables 1.0
import GlobalColors 1.0
import "../Components"

Item {
    id: root
    property int firstColumnWidth: width/4

    Component{
        id: labelText
        Text{
            id: labelTextText
            color: "white"
            text: label
            horizontalAlignment: Text.AlignRight
            width: firstColumnWidth
        }
    }

    Component{
        id: barGraph

        Item{
            id: barGraphItem
            width: 200
            height: 20

            Rectangle{
                width: parent.width
                height: 10
                color: "gray"
                anchors.verticalCenter: parent.verticalCenter

                Rectangle{
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    color: GlobalColors.orange
                    width: channel / 2000 * barGraphItem.width
                }
            }
        }

    }

    Text{
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 30
        text: "EGT"
        color: GlobalColors.white
    }

    Row{
        anchors.centerIn: parent
        spacing: 20

        Column{
            width: firstColumnWidth - 5
            spacing: 10
            Loader{ sourceComponent: labelText; property string label: "Cyl 1" }
            Loader{ sourceComponent: labelText; property string label: "Cyl 2" }
            Loader{ sourceComponent: labelText; property string label: "Cyl 3" }
            Loader{ sourceComponent: labelText; property string label: "Cyl 4" }
            Loader{ sourceComponent: labelText; property string label: "Cyl 5" }
            Loader{ sourceComponent: labelText; property string label: "Cyl 6" }
            Loader{ sourceComponent: labelText; property string label: "Cyl 7" }
            Loader{ sourceComponent: labelText; property string label: "Cyl 8" }
        }

        Column{
            width: root.width/4*3 - 5
            spacing: 10
            Loader{ sourceComponent: barGraph; property real channel: GlobalVariables.egt1 }
            Loader{ sourceComponent: barGraph; property real channel: GlobalVariables.egt2 }
            Loader{ sourceComponent: barGraph; property real channel: GlobalVariables.egt3 }
            Loader{ sourceComponent: barGraph; property real channel: GlobalVariables.egt4 }
            Loader{ sourceComponent: barGraph; property real channel: GlobalVariables.egt5 }
            Loader{ sourceComponent: barGraph; property real channel: GlobalVariables.egt6 }
            Loader{ sourceComponent: barGraph; property real channel: GlobalVariables.egt7 }
            Loader{ sourceComponent: barGraph; property real channel: GlobalVariables.egt8 }
        }

    }

}
