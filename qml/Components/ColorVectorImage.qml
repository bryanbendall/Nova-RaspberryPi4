import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {

    property alias imageSource: img.source
    property alias color: overlay.color

    Image {
        id: img
        sourceSize.width: parent.width
        sourceSize.height: parent.height
        visible: false
    }

    ColorOverlay{
        id: overlay
        source: img
        anchors.fill: img
    }

}
