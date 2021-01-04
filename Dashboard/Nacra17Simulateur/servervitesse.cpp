#include "servervitesse.h"

servervitesse::servervitesse(quint16 port, QObject *parent):QObject(parent)
{
    _server = new QTcpServer(this);

    connect(_server, SIGNAL(newConnection()),this, SLOT(newConnection()));


    if (!_server->listen(QHostAddress::Any, port)) {

        qDebug() << "Server could not start !" ;
    } else {
         qDebug() << "Server Vitesse started !" << _server->serverAddress() ;

    }
}

void servervitesse::newConnection() {

    _socket = _server->nextPendingConnection();


    qDebug() << "Someone connected !!";
    isconnected=true;
    connect(_socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));


        //startStreamingData() ;

}

void servervitesse::bytesWritten(qint64 nb){
     //qDebug() << "" << nb << " Bytes sent ..." ;
}

void servervitesse::update(float newval)
{


    if (isconnected==true){

        float f = newval;
         //qDebug() <<f;
        QByteArray x(reinterpret_cast<const char *>(&f), sizeof(f)) ;
        a=x;
           _socket->write(a);
           _socket->flush();
    }



}


void servervitesse::startStreamingData() //frequence timer à regler
{
    auto timer = new QTimer();
    timer->setInterval(100);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();


}




