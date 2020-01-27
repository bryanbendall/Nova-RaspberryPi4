import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtPositioning 5.6
import QtLocation 5.6

Item {
    id: root
    visible: true
//    title: qsTr("Hello World")
//    width: 1280
//    height: 800

    Rectangle{
        color: "black"
        width: parent.height
        height: parent.width
        x: 271
        y: 271

        transform: Rotation{
            angle: 90
            origin.x: width / 2
            origin.y: height / 2
        }

        GuageLayout{}

//        HolleyCanListView{}

        Map {
            id: map
            anchors.bottom: parent.bottom
            width: parent.width
            height: 400
            plugin: mapboxglPlugin
            center: QtPositioning.coordinate(42.3526257,-83.2392886) // Detroit
            zoomLevel: 8
            copyrightsVisible: false
            tilt: 45
        }

        Button{
            anchors.bottom: map.top
            anchors.centerIn: parent
            width: 200
            height: 80
            text: "Start Qt Can"
            onClicked: qtCanControl.connectToCan()
        }

    }

    Plugin {
        id: mapboxglPlugin
        name: "mapboxgl"
        PluginParameter { name: "mapboxgl.mapping.additional_style_urls";
                          value: "http://localhost:7000/dark-matter.style" }

        PluginParameter { name: "mapboxgl.mapping.cache.memory";
                          value: "true" }

    }



}
