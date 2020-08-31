import QtQuick 2.0
import GlobalColors 1.0

Image{
   source: "Images/OdometerBackground.png"

   Column{
       anchors.top: parent.top
       anchors.topMargin: 10
       anchors.horizontalCenter: parent.horizontalCenter
       Text {
           color: GlobalColors.white
           text: "Odometer"
           font.pointSize: 12
           anchors.horizontalCenter: parent.horizontalCenter
       }
       Text {
           color: GlobalColors.white
           text: "4456 km"
           font.pointSize: 16
           anchors.horizontalCenter: parent.horizontalCenter
       }
   }
}
