QT += quick network location serialport serialbus
CONFIG += c++17
LIBS += -lstdc++fs

include(QtWebApp/QtWebApp/httpserver/httpserver.pri)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(Nova):DEFINES += NOVA \
                        HOLLEYV4
CONFIG(Camaro):DEFINES += CAMARO \
                          HOLLEYV4
CONFIG(Pc):DEFINES += HOLLEYV4

#QMAKE_POST_LINK += sudo setpcap CAP_NET_ADMIN=eip NovaTablet

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringPi.c \
    ../../Downloads/wiringPi-8d188fa/wiringPi/softPwm.c \
    ../../Downloads/wiringPi-8d188fa/wiringPi/softTone.c \
    ../../Downloads/wiringPi-8d188fa/wiringPi/piHiPri.c \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringSerial.c \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringPiSPI.c \
    src/holleycancontrol.cpp \
    src/bluetoothwatcher.cpp \
    src/racepakcancontrol.cpp \
    src/novacancontrol.cpp \
    src/wificontroller.cpp \
    src/bryteccan.cpp \
    src/BrytecConfigEmbedded/EBrytecApp.cpp \
    src/BrytecConfigEmbedded/ENode.cpp \
    src/BrytecConfigEmbedded/IOTypes.cpp \
    src/BrytecConfigEmbedded/Can/EBrytecCan.cpp \
    src/BrytecConfigEmbedded/Can/ECanBus.cpp \
    src/BrytecConfigEmbedded/Can/ECanCommandQueue.cpp \
    src/BrytecConfigEmbedded/Can/ECanHolleyBroadcastQueue.cpp \
    src/BrytecConfigEmbedded/Can/ECustomCanQueue.cpp \
    src/BrytecConfigEmbedded/Can/EPinStatusQueue.cpp \
    src/BrytecConfigEmbedded/Deserializer/BinaryArrayDeserializer.cpp \
    src/BrytecConfigEmbedded/Deserializer/BinaryAvrEepromDeserializer.cpp \
    src/BrytecConfigEmbedded/Deserializer/BinaryBufferSerializer.cpp \
    src/BrytecConfigEmbedded/Deserializer/BinaryPathDeserializer.cpp \
    src/BrytecConfigEmbedded/Deserializer/BinaryProgmemDeserializer.cpp \
    src/BrytecConfigEmbedded/Nodes/EAndNode.cpp \
    src/BrytecConfigEmbedded/Nodes/ECanBusInputNode.cpp \
    src/BrytecConfigEmbedded/Nodes/ECanBusOutputNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EColorNode.cpp \
    src/BrytecConfigEmbedded/Nodes/ECompareNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EConvertNode.cpp \
    src/BrytecConfigEmbedded/Nodes/ECounterNode.cpp \
    src/BrytecConfigEmbedded/Nodes/ECurveNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EDelayNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EFinalValueNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EHolleyBroadcastNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EInitialValueNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EInterpolateNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EInvertNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EMapValueNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EMathNode.cpp \
    src/BrytecConfigEmbedded/Nodes/ENodeGroupNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EOnOffNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EOrNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EPIDNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EPinCurrentNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EPushButtonNode.cpp \
    src/BrytecConfigEmbedded/Nodes/ERacepakSwitchPanelNode.cpp \
    src/BrytecConfigEmbedded/Nodes/ESwitchNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EToggleNode.cpp \
    src/BrytecConfigEmbedded/Nodes/ETwoStageNode.cpp \
    src/BrytecConfigEmbedded/Nodes/EValueNode.cpp \
    src/BrytecConfigEmbedded/Usb/UsbDefs.cpp \
    src/BrytecConfigEmbedded/Utils/ENodeDeserializer.cpp \
    src/BrytecConfigEmbedded/Utils/ENodeGroup.cpp \
    src/BrytecConfigEmbedded/Utils/PlacementNew.cpp \
    src/screenboard.cpp

RESOURCES += qml.qrc \
    res.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
INSTALLS = target
target.path = /home/pi
target.files = NovaTablet

HEADERS += \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringPi.h \
    ../../Downloads/wiringPi-8d188fa/wiringPi/softPwm.h \
    ../../Downloads/wiringPi-8d188fa/wiringPi/softTone.h \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringSerial.h \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringPiSPI.h \
    src/holleycancontrol.h \
    src/bluetoothwatcher.h \
    src/racepakcancontrol.h \
    src/novacancontrol.h \
    src/holleyvariablesv6.h \
    src/holleyvariablesv4.h \
    src/wificontroller.h \
    src/bryteccan.h \
    src/BrytecConfigEmbedded/EBrytecApp.h \
    src/BrytecConfigEmbedded/EBrytecConfig.h \
    src/BrytecConfigEmbedded/ENode.h \
    src/BrytecConfigEmbedded/IOTypes.h \
    src/BrytecConfigEmbedded/Boards/BrytecBoard.h \
    src/BrytecConfigEmbedded/Can/EBrytecCan.h \
    src/BrytecConfigEmbedded/Can/ECanBus.h \
    src/BrytecConfigEmbedded/Can/ECanCommandQueue.h \
    src/BrytecConfigEmbedded/Can/ECanHolleyBroadcastQueue.h \
    src/BrytecConfigEmbedded/Can/ECustomCanQueue.h \
    src/BrytecConfigEmbedded/Can/EPinStatusQueue.h \
    src/BrytecConfigEmbedded/Deserializer/BinaryArrayDeserializer.h \
    src/BrytecConfigEmbedded/Deserializer/BinaryAvrEepromDeserializer.h \
    src/BrytecConfigEmbedded/Deserializer/BinaryBufferSerializer.h \
    src/BrytecConfigEmbedded/Deserializer/BinaryDeserializer.h \
    src/BrytecConfigEmbedded/Deserializer/BinaryPathDeserializer.h \
    src/BrytecConfigEmbedded/Deserializer/BinaryProgmemDeserializer.h \
    src/BrytecConfigEmbedded/Nodes/EAndNode.h \
    src/BrytecConfigEmbedded/Nodes/ECanBusInputNode.h \
    src/BrytecConfigEmbedded/Nodes/ECanBusOutputNode.h \
    src/BrytecConfigEmbedded/Nodes/EColorNode.h \
    src/BrytecConfigEmbedded/Nodes/ECompareNode.h \
    src/BrytecConfigEmbedded/Nodes/EConvertNode.h \
    src/BrytecConfigEmbedded/Nodes/ECounterNode.h \
    src/BrytecConfigEmbedded/Nodes/ECurveNode.h \
    src/BrytecConfigEmbedded/Nodes/EDelayNode.h \
    src/BrytecConfigEmbedded/Nodes/EFinalValueNode.h \
    src/BrytecConfigEmbedded/Nodes/EHolleyBroadcastNode.h \
    src/BrytecConfigEmbedded/Nodes/EInitialValueNode.h \
    src/BrytecConfigEmbedded/Nodes/EInterpolateNode.h \
    src/BrytecConfigEmbedded/Nodes/EInvertNode.h \
    src/BrytecConfigEmbedded/Nodes/EMapValueNode.h \
    src/BrytecConfigEmbedded/Nodes/EMathNode.h \
    src/BrytecConfigEmbedded/Nodes/ENodeGroupNode.h \
    src/BrytecConfigEmbedded/Nodes/EOnOffNode.h \
    src/BrytecConfigEmbedded/Nodes/EOrNode.h \
    src/BrytecConfigEmbedded/Nodes/EPIDNode.h \
    src/BrytecConfigEmbedded/Nodes/EPinCurrentNode.h \
    src/BrytecConfigEmbedded/Nodes/EPushButtonNode.h \
    src/BrytecConfigEmbedded/Nodes/ERacepakSwitchPanelNode.h \
    src/BrytecConfigEmbedded/Nodes/ESwitchNode.h \
    src/BrytecConfigEmbedded/Nodes/EToggleNode.h \
    src/BrytecConfigEmbedded/Nodes/ETwoStageNode.h \
    src/BrytecConfigEmbedded/Nodes/EValueNode.h \
    src/BrytecConfigEmbedded/Usb/UsbDefs.h \
    src/BrytecConfigEmbedded/Utils/EBrytecErrors.h \
    src/BrytecConfigEmbedded/Utils/ENodeConnection.h \
    src/BrytecConfigEmbedded/Utils/ENodeDeserializer.h \
    src/BrytecConfigEmbedded/Utils/ENodeGroup.h \
    src/BrytecConfigEmbedded/Utils/ENodesVector.h \
    src/BrytecConfigEmbedded/Utils/PlacementNew.h \
    src/screenboarddefs.h \
    src/screeninternaldefs.h

INCLUDEPATH += \
    ../../Downloads/wiringPi-8d188fa/wiringPi/ \
    ../../Downloads/spi_can/ \
    QtWebApp/QtWebApp/httpserver/ \
    src/BrytecConfigEmbedded/

DISTFILES += \

