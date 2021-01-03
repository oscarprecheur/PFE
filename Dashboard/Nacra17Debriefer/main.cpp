#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QtGui>

#include "readfile.h" //appel de la classe readfile

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);//Instanciation de l'application

    qmlRegisterType<readfile>("READ.FILE",1,0,"READFILE"); // creation du registre qml READFILE permetant d'acceder au fonctino de la clase readFile

    QQmlApplicationEngine engine; //Création du moteur de l'applciation
    QQmlComponent component(&engine, QUrl(QLatin1String("qrc:/MemoDashboard.qml")));//Instanciation du composant qml MemoDashboard grace au moteur crée


    component.create(); //création du composant

    return app.exec(); // lancement de l'application
}
