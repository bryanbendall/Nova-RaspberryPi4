import QtQuick 2.0
import QtPositioning 5.6
import QtLocation 5.6

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
        color: "blue"

        Map {
            id: map
            anchors.top: parent.top
            anchors.left: parent.left
            width: parent.width
            height: parent.height / 2
            plugin: mapboxglPlugin
            center: QtPositioning.coordinate(42.3526257,-83.2392886) // Detroit
            zoomLevel: 8
            copyrightsVisible: false
            tilt: 45
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
}
