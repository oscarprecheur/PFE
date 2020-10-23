#include "servertangage.h"

#include<QTimer>
#include<cmath>



servertangage::servertangage(quint16 port, QObject *parent):QObject(parent)
{
    _server = new QTcpServer(this);

    connect(_server, SIGNAL(newConnection()),this, SLOT(newConnection()));


    if (!_server->listen(QHostAddress::Any, port)) {

        qDebug() << "Server could not start !" ;
    } else {
         qDebug() << "Server Accelero started !" << _server->serverAddress() ;
    }
}

void servertangage::newConnection() {

    _socket = _server->nextPendingConnection();

    qDebug() << "Someone connected !!";

    connect(_socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));

    startStreamingData() ;

}

void servertangage::bytesWritten(qint64 nb){
     qDebug() << "" << nb << " Bytes sent ..." ;
}

void servertangage::update(int newval)
{

//    while(1) {

        float f = (float)newval;
         qDebug() <<f;
        QByteArray x(reinterpret_cast<const char *>(&f), sizeof(f)) ;
        a=x;


           _socket->write(a);



           _socket->flush();



//    }


}

float servertangage::getNextValue() //Return valeur capteur exploitable
{

    updatecpt();

    return 180*sin(cpt/10) ;



    //return (float)2;//a remplacer
}

void servertangage::startStreamingData() //frequence timer à regler
{
    auto timer = new QTimer();
    timer->setInterval(100);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();


}

void servertangage::updatecpt()
{
    cpt++;

}


