#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "appglobal.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    auto appGlobal = new AppGlobal;
    engine.rootContext()->setContextProperty("$app", appGlobal);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    auto result = app.exec();
    delete appGlobal;
    return result;
}
