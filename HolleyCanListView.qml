import QtQuick 2.0

ListView {
    id: root
    anchors.fill: parent
    anchors.topMargin: 50

    model: holleyModel

    delegate: Rectangle{
        width: root.width
        height: 30
        color: "transparent"

        Text{
            color: "white"
//            text: "    " + item.address + "    -    " + item.data0 + "  " + item.data1 + "  " + item.data2 + "  " + item.data3
//                  + "  " + item.data4 + "  " + item.data5 + "  " + item.data6 + "  " + item.data7 + " " + item.label
            text: "    " + item.address + "    -    " + item.label
        }
    }

    Component.onCompleted: {
        holleyCanControl.startCan()
    }
}
