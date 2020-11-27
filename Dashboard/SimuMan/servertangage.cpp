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
         qDebug() << "Server Tangage started !" << _server->serverAddress() ;
    }
}

void servertangage::newConnection() {

    _socket = _server->nextPendingConnection();

    qDebug() << "Someone connected !!";
    isconnected=true;
    connect(_socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));


        //startStreamingData() ;


}
void servertangage::bytesWritten(qint64 nb){
     qDebug() << "" << nb << " Bytes sent ..." ;
}

void servertangage::update(int newval)
{
    if (isconnected==true){

        float f = (float)newval;
         //qDebug() <<f;
        QByteArray x(reinterpret_cast<const char *>(&f), sizeof(f)) ;
        a=x;
           _socket->write(a);
           _socket->flush();
    }



}

void servertangage::startStreamingData() //frequence timer à regler
{
    auto timer = new QTimer();
    timer->setInterval(100);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();


}



