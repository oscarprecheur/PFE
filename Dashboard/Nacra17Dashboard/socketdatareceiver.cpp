#include "socketdatareceiver.h"
#include <QTimer>

SocketDataReceiver::SocketDataReceiver(QObject *parent):QObject(parent)
{

}

void SocketDataReceiver::Connexion(quint16 port)
{
    _port = port;
    _socket = new QTcpSocket();


    _socket->connectToHost("127.0.0.1", _port);


     qDebug() << "Receiver connected " ;

}

float SocketDataReceiver::readyRead()
{




    QByteArray r = _socket->read(4) ;
    _lastValue = *reinterpret_cast<const float *>(r.data() );

    return getLastValue();


}

float SocketDataReceiver::transmit()
{

    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    return NULL;

}


float SocketDataReceiver::getLastValue()
{

     return _lastValue ;

}

float SocketDataReceiver::getNbByteAvailable()
{
    return _socket->bytesAvailable();
}

bool SocketDataReceiver::available()
{
    return _socket->waitForReadyRead();
}
