#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include "valcapt.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<valcapt>("VAL.CAPT",1,0,"VALCAPT");

    QQmlApplicationEngine engine;

    QQmlComponent component(&engine, QUrl(QLatin1String("qrc:/main.qml")));

    component.create();

    return app.exec();
}
