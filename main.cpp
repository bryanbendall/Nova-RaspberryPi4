#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCursor>
#include "wiringPi.h"
#include "wiringSerial.h"
#include "serialcomm.h"
#include "lightcontrol.h"
#include "datareciever.h"
#include "windowcontrol.h"
//#include "bluetoothcontrol.h"
#include "cancontrol.h"
#include <QSurfaceFormat>
//#include "holleycancontrol.h"
#include <QDebug>
#include <QSerialPortInfo>
#include "qtcancontrol.h"
#include <QQuickView>
#include <QScreen>
#include <QRect>
#include <QFontDatabase>

int main(int argc, char *argv[])
{

#ifdef RASPPI
    qDebug() << "wiring pi setup: " << wiringPiSetupSys();
#endif

//    qputenv("QT_LOGGING_RULES", "qt.qpa.*=true");
//    qputenv("QSG_INFO", "1");

//    BluetoothControl btControl;

//    CanControl canControl;

//    SerialComm serial;
//    LightControl lightControl(&serial);
//    WindowControl windowControl(&serial);
//    DataReciever dataReciever(&serial, &lightControl);
//    QtCanControl qtCanControl;



    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

//    qint32 fontId = QFontDatabase::addApplicationFont(":/Fonts/Orbitron-Black.ttf");
    qint32 fontId = QFontDatabase::addApplicationFont(":/Fonts/RussoOne-Regular.ttf");
    QStringList fontList = QFontDatabase::applicationFontFamilies(fontId);

    QString family = fontList.at(0);
    QGuiApplication::setFont(QFont(family));

////    app.setOverrideCursor(Qt::BlankCursor);
//    engine.rootContext()->setContextProperty("lightControl", &lightControl);
//    engine.rootContext()->setContextProperty("windowControl", &windowControl);
////    engine.rootContext()->setContextProperty("btControl", &btControl);
//    engine.rootContext()->setContextProperty("canControl", &canControl);
//    engine.rootContext()->setContextProperty("qtCanControl", &qtCanControl);

//    HolleyCanControl holleyCanControl(engine.rootContext(), nullptr);
//    engine.rootContext()->setContextProperty("holleyCanControl", &holleyCanControl);
//    engine.rootContext()->setContextProperty("holleyModel", &holleyCanControl.getHolleyModel());

//    qDebug() << "Number of serial ports" << QSerialPortInfo::availablePorts().length();
//    for(auto sp : QSerialPortInfo::availablePorts()){
//        qDebug() << sp.portName() << " " << sp.description() << " " << sp.manufacturer() << " " << sp.serialNumber() << " " << sp.systemLocation();
//    }

#ifdef RASPPI
    QList<QScreen *> screens = app.screens();
    qDebug("Application sees %d screens", screens.count());
    qDebug() << screens;

    QVector<QQuickView *> views;
    for (int i = 0; i < screens.count(); ++i) {

        QQuickView *v = new QQuickView;
        views.append(v);

        v->setScreen(screens[i]);
        v->setResizeMode(QQuickView::SizeRootObjectToView);

        v->rootContext()->setContextProperty("screenIdx", i);
        v->rootContext()->setContextProperty("screenGeom", screens[i]->geometry());
        v->rootContext()->setContextProperty("screenAvailGeom", screens[i]->availableGeometry());
        v->rootContext()->setContextProperty("screenVirtGeom", screens[i]->virtualGeometry());
        v->rootContext()->setContextProperty("screenAvailVirtGeom", screens[i]->availableVirtualGeometry());
        v->rootContext()->setContextProperty("screenPhysSizeMm", screens[i]->physicalSize());
        v->rootContext()->setContextProperty("screenRefresh", screens[i]->refreshRate());

//        v->engine()->rootContext()->setContextProperty("lightControl", &lightControl);
//        v->engine()->rootContext()->setContextProperty("canControl", &canControl);

        switch (i) {
        case 0:
            v->setSource(QUrl("qrc:/CenterScreen.qml"));
            qDebug() << "Center Screen";
            break;
        case 1:
            v->setSource(QUrl("qrc:/GuagesScreen.qml"));
            qDebug() << "Guages Screen";
            break;
        }

        v->showFullScreen();
    }
#endif

#ifndef RASPPI
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ComputerWrapper.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
#endif

    int r = app.exec();
#ifdef RASPPI
    qDeleteAll(views);
#endif
    return r;
}
