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

int main(int argc, char *argv[])
{

#if defined(CAMARO) || defined(NOVA)
//    qDebug() << "wiring pi setup: " << wiringPiSetupSys();
#endif

//    qputenv("QT_LOGGING_RULES", "qt.qpa.*=true");
//    qputenv("QSG_INFO", "1");


    BluetoothWatcher watcher;
    HolleyCanControl holleyCan;
#ifdef CAMARO
    RacepakCanControl racepakCan;
    qmlRegisterSingletonType(QUrl("qrc:/CamaroVariables.qml"), "GlobalVariables", 1, 0, "GlobalVariables");
#endif
#ifdef NOVA
    NovaCanControl novaCan;
    qmlRegisterSingletonType(QUrl("qrc:/NovaVariables.qml"), "GlobalVariables", 1, 0, "GlobalVariables");
#endif



    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

//    qint32 fontId = QFontDatabase::addApplicationFont(":/Fonts/Orbitron-Black.ttf");
    qint32 fontId = QFontDatabase::addApplicationFont(":/Fonts/RussoOne-Regular.ttf");
    QStringList fontList = QFontDatabase::applicationFontFamilies(fontId);

    QString family = fontList.at(0);
    QGuiApplication::setFont(QFont(family));

////    app.setOverrideCursor(Qt::BlankCursor);

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

#if !defined(CAMARO) && !defined(NOVA)
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("holleyCan", &holleyCan);
#ifdef CAMARO
    engine.rootContext()->setContextProperty("racepakCan", &racepakCan);
#endif
    NovaCanControl novaCan;
    engine.rootContext()->setContextProperty("novaCan", &novaCan);


    qmlRegisterSingletonType(QUrl("qrc:/NovaVariables.qml"), "GlobalVariables", 1, 0, "GlobalVariables");

    engine.load(QUrl(QStringLiteral("qrc:/ComputerWrapper.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;
#endif



    int r = app.exec();
#if defined(CAMARO) || defined(NOVA)
    qDeleteAll(views);
#endif
    return r;
}
