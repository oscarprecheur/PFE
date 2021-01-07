#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QTextStream>

#include "valcapt.h"
#include "valmoy.h"


int main(int argc, char *argv[])
{
//        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//        QGuiApplication app(argc, argv);

//        qmlRegisterType<valcapt>("VAL.CAPT",1,0,"VALCAPT");

//        QQmlApplicationEngine engine;

//        QQmlComponent component(&engine, QUrl(QLatin1String("qrc:/main.qml")));

//        component.create();

//        return app.exec();

    valmoy val;
    int vitesse;
    int distance;
    QTextStream s(stdin);

    while(1)
    {
        qDebug()<<"vitesse";
        vitesse = s.readLine().toInt();
        qDebug()<<"distance";
        distance = s.readLine().toInt();

        val.addData(vitesse,distance);


    }
}
