import QtQuick 2.0
import GlobalVariables 1.0
import GlobalColors 1.0
import "../Components"

Item {
    width: 350
    height: 480

    Column{
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 100
        spacing: 20
        CircularGauge{
            id: tempGauge
            width: 160
            height: 160
            minValue: 30
            maxValue: 250
            value: GlobalVariables.cts
            highWarn: 200
            units: "°F"
            image: "../../Images/water-temp.svg"
            ColorVectorImage{
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                width: 50
                height: 50
                imageSource: "../../Images/fan.svg"
                color: GlobalColors.blue
                visible: GlobalVariables.fanState
            }
        }

        CircularGauge{
            id: oilGauge
            width: 160
            height: 160
            minValue: 0
            maxValue: 100
            value: GlobalVariables.oilPressure
            lowWarn: 5
            units: "PSI"
            image: "../../Images/engine-oil.svg"
        }
    }

}
