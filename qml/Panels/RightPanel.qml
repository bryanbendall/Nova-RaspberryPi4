import QtQuick 2.0
import QtQuick.Controls 2.0
import GlobalVariables 1.0
import GlobalColors 1.0
import "../Components"

SwipeView {
    id: swipeView
    width: 350
    height: 380
    currentIndex: 0
    clip: true

    InfoPanel{}

    RacepakInputsPanel{ id: racepakInputsPanel }

    EgtPanel{ id: egtPanel }

    Component.onCompleted: {
        if(typeof racepakCan === 'undefined'){
            swipeView.removeItem(racepakInputsPanel)
        }
    }

}
