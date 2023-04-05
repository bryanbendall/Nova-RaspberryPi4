import QtQuick 2.7
import GlobalVariables 1.0
import GlobalColors 1.0
import "../Components"

Item {
    id: root
    property int firstColumnWidth: width/4*3

    Component{
        id: labelText
        Text{
            color: "white"
            text: label
            horizontalAlignment: Text.AlignRight
            width: firstColumnWidth
        }
    }

    Component{
        id: valueText
        Text{
            color: channel ? GlobalColors.green : GlobalColors.red
            text: typeof racepakCan === 'undefined' ? "N/A" : channel
        }
    }

    Row{
        anchors.centerIn: parent
        spacing: 10

        Column{
            width: firstColumnWidth - 5
            Loader{ sourceComponent: labelText; property string label: "Switch Module 1" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 2" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 3" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 4" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 5" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 6" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 7" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 8" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 9" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 10" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 11" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 12" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 13" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 14" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 15" }
            Loader{ sourceComponent: labelText; property string label: "Switch Module 16" }
        }

        Column{
            width: root.width/2 - 5
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_1_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_2_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_3_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_4_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_5_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_6_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_7_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_8_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_9_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_10_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_11_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_12_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_13_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_14_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_15_Status }
            Loader{ sourceComponent: valueText; property bool channel: racepakCan.Module_Input_16_Status }
        }

    }

}
