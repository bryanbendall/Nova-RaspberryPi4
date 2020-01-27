QT += quick network location serialport serialbus
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(RaspPi):DEFINES += RASPPI

#QMAKE_POST_LINK += sudo setpcap CAP_NET_ADMIN=eip NovaTablet

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringPi.c \
    ../../Downloads/wiringPi-8d188fa/wiringPi/softPwm.c \
    ../../Downloads/wiringPi-8d188fa/wiringPi/softTone.c \
    ../../Downloads/wiringPi-8d188fa/wiringPi/piHiPri.c \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringSerial.c \
    serialcomm.cpp \
    lightcontrol.cpp \
    datareciever.cpp \
    windowcontrol.cpp \
    bluetoothcontrol.cpp \
    ../../Downloads/spi_can/spi_can.cpp \
    spi.cpp \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringPiSPI.c \
    cancontrol.cpp \
    holleycanmsg.cpp \
    holleycancontrol.cpp \
    holleycanmodel.cpp \
    qtcancontrol.cpp \

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
    serialcomm.h \
    tabcommdefs.h \
    lightcontrol.h \
    datareciever.h \
    windowcontrol.h \
    bluetoothcontrol.h \
    ../../Downloads/spi_can/spi_can.h \
    ../../Downloads/spi_can/spi_can_defs.h \
    ../../Downloads/spi_can/spi_can_msg.h \
    spi.h \
    ../../Downloads/wiringPi-8d188fa/wiringPi/wiringPiSPI.h \
    cancontrol.h \
    holleycanmsg.h \
    holleycancontrol.h \
    holleycanmodel.h \
    qtcancontrol.h \

INCLUDEPATH += \
    ../../Downloads/wiringPi-8d188fa/wiringPi/ \
    ../../Downloads/spi_can/ \

DISTFILES +=
