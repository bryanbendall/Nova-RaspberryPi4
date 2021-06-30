import QtQuick 2.0
import GlobalVariables 1.0
import GlobalColors 1.0
import "../Components"

Item {
    width: 450
    height: 60

    Row{
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 125
        spacing: 20

        ColorVectorImage{
            width: 50
            height: 50
            imageSource: "../../Images/parking-brake.svg"
            color: GlobalColors.red
            visible: GlobalVariables.parkingBrakeState
        }

        ColorVectorImage{
            width: 50
            height: 50
            imageSource: "../../Images/high-beam.svg"
            color: GlobalColors.blue
            visible: GlobalVariables.highbeamIndicatorState
        }
    }


}
