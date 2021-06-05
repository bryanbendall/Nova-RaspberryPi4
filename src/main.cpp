#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCursor>
#include <QDebug>
#include <QQuickView>
#include <QScreen>
#include <QFontDatabase>
#include "bluetoothwatcher.h"
#include "holleycancontrol.h"
#include "racepakcancontrol.h"
#include "novacancontrol.h"
#include <QSettings>
#include "httplistener.h"
#include "wificontroller.h"

using namespace stefanfrings;

void registerQmlGlobals(){
#ifdef CAMARO
    qmlRegisterSingletonType(QUrl("qrc:/qml/GlobalVariables/CamaroVariables.qml"), "GlobalVariables", 1, 0, "GlobalVariables");
#else
    qmlRegisterSingletonType(QUrl("qrc:/qml/GlobalVariables/NovaVariables.qml"), "GlobalVariables", 1, 0, "GlobalVariables");
#endif

    qmlRegisterSingletonType(QUrl("qrc:/qml/GlobalVariables/GlobalColors.qml"), "GlobalColors", 1, 0, "GlobalColors");
}

void setupFont(){
//    qint32 fontId = QFontDatabase::addApplicationFont(":/Fonts/Orbitron-Black.ttf");
    qint32 fontId = QFontDatabase::addApplicationFont(":/Fonts/RussoOne-Regular.ttf");
    QStringList fontList = QFontDatabase::applicationFontFamilies(fontId);

    QString family = fontList.at(0);
    QGuiApplication::setFont(QFont(family));
}

void hideCursor(QGuiApplication& app){
    app.setOverrideCursor(Qt::BlankCursor);
}

void setupHttpServer(QGuiApplication& app){
    // Http server from:
    // http://stefanfrings.de/qtwebapp/tutorial/index.html#part2
    QSettings* listenerSettings = new QSettings(":/etc/server.ini",QSettings::IniFormat,&app);
    qDebug("config file loaded");
    listenerSettings->beginGroup("listener");

    // Start the HTTP server
    new HttpListener(listenerSettings, new WifiController(&app), &app);
}

int main(int argc, char *argv[])
{

#if defined(CAMARO) || defined(NOVA)
//    qDebug() << "wiring pi setup: " << wiringPiSetupSys();
#endif

      qputenv("QT_QPA_EGLFS_ALWAYS_SET_MODE", "1");
//    qputenv("QT_LOGGING_RULES", "qt.qpa.*=true");
//    qputenv("QSG_INFO", "1");


    //BluetoothWatcher watcher;
    HolleyCanControl holleyCan;
#ifdef CAMARO
    RacepakCanControl racepakCan;
#else
    NovaCanControl novaCan;
#endif

    registerQmlGlobals();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    setupFont();
    hideCursor(app);
    setupHttpServer(app);

// This is for pc testing only
#if !defined(CAMARO) && !defined(NOVA)
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("holleyCan", &holleyCan);
    engine.rootContext()->setContextProperty("novaCan", &novaCan);
    engine.load(QUrl(QStringLiteral("qrc:/qml/Screens/ComputerWrapper.qml")));
#endif

#if defined(CAMARO) || defined(NOVA)
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

        v->engine()->rootContext()->setContextProperty("holleyCan", &holleyCan);
#ifdef CAMARO
        v->engine()->rootContext()->setContextProperty("racepakCan", &racepakCan);
#endif
#ifdef NOVA
        v->engine()->rootContext()->setContextProperty("novaCan", &novaCan);
#endif

        switch (i) {
        case 0:
            v->setSource(QUrl("qrc:/qml/Screens/GuagesScreen.qml"));
            qDebug() << "Guages Screen";
            break;
        case 1:
            v->setSource(QUrl("qrc:/qml/Screens/CenterScreen.qml"));
            qDebug() << "Center Screen";
            break;
        }

        v->showFullScreen();
    }
#endif

    int r = app.exec();

#if defined(CAMARO) || defined(NOVA)
    qDeleteAll(views);
#endif
    return r;
}
