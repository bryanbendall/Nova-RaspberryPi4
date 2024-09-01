import QtQuick 2.0
import QtPositioning 5.6
import QtLocation 5.6
import QtQuick.Controls 2.4

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
        color: "black"
        id: root
        property int firstColumnWidth: width/2

//        Map {
//            id: map
//            anchors.top: parent.top
//            anchors.left: parent.left
//            width: parent.width
//            height: parent.height / 2
//            plugin: mapboxglPlugin
//            center: QtPositioning.coordinate(42.3526257,-83.2392886) // Detroit
//            zoomLevel: 8
//            copyrightsVisible: false
//            tilt: 45
//        }

//        Plugin {
//            id: mapboxglPlugin
//            name: "mapboxgl"
////            PluginParameter { name: "mapboxgl.mapping.additional_style_urls";
////                              value: "http://localhost:7000/dark-matter.style" }

//            PluginParameter { name: "mapboxgl.mapping.cache.memory";
//                              value: "true" }

//        }

        Text{
            id: odo
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 50
            font.pointSize: 20
            height: 50
            color: "white"
            text: "Odometer test: " + holleyCan.Odometer + " Miles";
        }

        Button{
            text: "Push"
            font.pointSize: 50
            anchors.top: odo.bottom
            onClicked: console.log("button pushed!!!!")
            onPressed: novaCan.TestButton = true
            onReleased: novaCan.TestButton = false
        }

//        Component{
//            id: labelText
//            Text{
//                color: "white"
//                text: label
//                horizontalAlignment: Text.AlignRight
//                width: root.firstColumnWidth
//            }
//        }

//        Component{
//            id: valueText
//            Text{
//                color: "white"
//                text: label
//            }
//        }

//        Row{
//            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.top: odo.bottom
//            spacing: 30

//            Column{
//                width: root.firstColumnWidth - 5
//                Loader{ sourceComponent: labelText; property string label: "Ignition" }
//                Loader{ sourceComponent: labelText; property string label: "Brake Lights" }
//                Loader{ sourceComponent: labelText; property string label: "Reverse Lights" }
//                Loader{ sourceComponent: labelText; property string label: "Left Turn" }
//                Loader{ sourceComponent: labelText; property string label: "Right Turn" }
//                Loader{ sourceComponent: labelText; property string label: "Parking Lights" }
//                Loader{ sourceComponent: labelText; property string label: "Low Beam" }
//                Loader{ sourceComponent: labelText; property string label: "High Beam" }
//                Loader{ sourceComponent: labelText; property string label: "Fog Lights" }
//                Loader{ sourceComponent: labelText; property string label: "Cooling Fan" }
//                Loader{ sourceComponent: labelText; property string label: "Gas Pump" }
//                Loader{ sourceComponent: labelText; property string label: "Meth Pump" }
//                Loader{ sourceComponent: labelText; property string label: "Start Button" }
//                Loader{ sourceComponent: labelText; property string label: "Neutral Safety" }
//            }

//            Column{
//                width: root.width/2 - 5
//                Loader{ sourceComponent: valueText; property string label: novaCan.Ignition }
//                Loader{ sourceComponent: valueText; property string label: novaCan.BrakeLights }
//                Loader{ sourceComponent: valueText; property string label: novaCan.ReverseLights }
//                Loader{ sourceComponent: valueText; property string label: novaCan.LeftTurn }
//                Loader{ sourceComponent: valueText; property string label: novaCan.RightTurn }
//                Loader{ sourceComponent: valueText; property string label: novaCan.ParkingLights }
//                Loader{ sourceComponent: valueText; property string label: novaCan.LowBeam }
//                Loader{ sourceComponent: valueText; property string label: novaCan.HighBeam }
//                Loader{ sourceComponent: valueText; property string label: novaCan.FogLights }
//                Loader{ sourceComponent: valueText; property string label: novaCan.CoolingFan }
//                Loader{ sourceComponent: valueText; property string label: novaCan.GasPump }
//                Loader{ sourceComponent: valueText; property string label: novaCan.MethPump }
//                Loader{ sourceComponent: valueText; property string label: novaCan.StartButton }
//                Loader{ sourceComponent: valueText; property string label: novaCan.NeutralSafety }

//            }

//        }

    }
}
