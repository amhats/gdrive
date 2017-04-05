#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSystemTrayIcon>
#include "systemtray.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    SystemTray* systemTray = new SystemTray();
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("systemTray", systemTray);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    return app.exec();
}
