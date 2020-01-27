import QtQuick 2.0

Image{
   source: "Images/OdometerBackground.png"

   Column{
       anchors.top: parent.top
       anchors.topMargin: 10
       anchors.horizontalCenter: parent.horizontalCenter
       Text {
           color: "#e5e5e5"
           text: "Odometer"
           font.pointSize: 12
           anchors.horizontalCenter: parent.horizontalCenter
       }
       Text {
           color: "#e5e5e5"
           text: "4456 km"
           font.pointSize: 16
           anchors.horizontalCenter: parent.horizontalCenter
       }
   }
}
