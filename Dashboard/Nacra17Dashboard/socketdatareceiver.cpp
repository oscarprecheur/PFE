#include "socketdatareceiver.h"

SocketDataReceiver::SocketDataReceiver(QObject *parent):QObject(parent)
{

}

void SocketDataReceiver::Connexion(quint16 port) //on se connecte au port numéro en paramètre
{
    _port = port;
    _socket = new QTcpSocket();//on crée une nouvelle variable de type QTcpSocket


    _socket->connectToHost("127.0.0.1", _port);//on connectre la socket au port de l'hote


     qDebug() << "Receiver connected " ;

}

float SocketDataReceiver::readyRead()//permet la lecture des données provenant du capteur ou du simulateur
{




    QByteArray r = _socket->read(4) ;//on lit la valeur de la socket sur 4bytes
    _lastValue = *reinterpret_cast<const float *>(r.data() );//on cast la données en float

    return getLastValue();


}

float SocketDataReceiver::transmit()
{

    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead())); // lorsque le signal readyRead de _socket est vrai on lance la méthode readyRead de la classe socketdatareceiver
    return NULL;

}


float SocketDataReceiver::getLastValue()
{

     return _lastValue ;

}

float SocketDataReceiver::getNbByteAvailable()//lecture du nombre de bytes disponibles dans la socket
{
    return _socket->bytesAvailable();
}

bool SocketDataReceiver::available()//test si la socket est prete à etre lue
{
    return _socket->waitForReadyRead();
}
