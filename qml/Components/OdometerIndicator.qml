import QtQuick 2.0
import GlobalColors 1.0
import GlobalVariables 1.0

Image{
   source: "../../Images/OdometerBackground.png"

   Column{
       anchors.top: parent.top
       anchors.topMargin: 10
       anchors.horizontalCenter: parent.horizontalCenter
       Text {
           color: GlobalVariables.showOdometer ? GlobalColors.gray : GlobalColors.white
           text: GlobalVariables.showOdometer ? "Odometer" : "J's"
           font.pointSize: 12
           anchors.horizontalCenter: parent.horizontalCenter
       }
       Text {
           color: GlobalColors.white
           text: GlobalVariables.showOdometer ? "4456 km" : "Peroformance"
           font.pointSize: GlobalVariables.showOdometer ? 16 : 12
           anchors.horizontalCenter: parent.horizontalCenter
       }
   }
}
