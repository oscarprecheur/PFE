//#include "mainwindow.h"

//#include <QApplication>
//#include "socketdatareceiver.h"

//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include <QQmlContext>
//#include <QtGui>

//#include "valcapt.h"



//int main(int argc, char *argv[])
//{

//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    QApplication a(argc, argv);






//    QQmlApplicationEngine engine;

//    qmlRegisterType<valcapt>("VAL.CAPT",1,0,"VALCAPT");//creation du registre valcapt (donnée capteur C++ -> QML)

//    const QUrl url(QStringLiteral("qrc:/main.qml"));//appel du programme QML d'affichage
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &a, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

//    return a.exec();//exectution de l'application




//}


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QtGui>
#include <QFloat16>
#include "mainwindow.h"

#include <QApplication>
#include "socketdatareceiver.h"
#include "valcapt.h"
#include "initialisation.h"


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
