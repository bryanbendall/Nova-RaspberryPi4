import QtQuick 2.0
import GlobalVariables 1.0
import "../Components"

Item {
    width: 350
    height: 100

    FuelGauges{
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 30
        anchors.bottomMargin: 20
        width: 300
        height: 100
    }

}
