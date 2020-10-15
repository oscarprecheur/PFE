#include "ServerBoussole.h"
#include<QTimer>
#include<cmath>



ServerBoussole::ServerBoussole(quint16 port, QObject *parent):QObject(parent)
{
    _server = new QTcpServer(this);

    connect(_server, SIGNAL(newConnection()),this, SLOT(newConnection()));


    if (!_server->listen(QHostAddress::Any, port)) {

        qDebug() << "Server could not start !" ;
    } else {
         qDebug() << "Server Boussole started !" << _server->serverAddress() ;
    }
}

void ServerBoussole::newConnection() {

    _socket = _server->nextPendingConnection();

    qDebug() << "Someone connected !!";

    connect(_socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));

    startStreamingData() ;

}

void ServerBoussole::bytesWritten(qint64 nb){
     qDebug() << "" << nb << " Bytes sent ..." ;
}

void ServerBoussole::update()
{
        float f = getNextValue();

        QByteArray x(reinterpret_cast<const char *>(&f), sizeof(f)) ;
        a=x;
        qDebug() << "message" << a ;

           _socket->write(a);



           _socket->flush();
}

float ServerBoussole::getNextValue() //Return valeur capteur exploitable
{

    updatecpt();

    return 180*sin(cpt/10) ;
}

void ServerBoussole::startStreamingData() //frequence timer à regler
{
    auto timer = new QTimer();
    timer->setInterval(100);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();


}

void ServerBoussole::updatecpt()
{
    cpt++;

}


