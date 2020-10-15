#ifndef SOCKETDATARECEIVER_H
#define SOCKETDATARECEIVER_H

#include <QTcpSocket>
#include <QObject>

class SocketDataReceiver : QObject
{

    Q_OBJECT
public:
    SocketDataReceiver( QObject*parent = nullptr);

    float getLastValue();
    float getNbByteAvailable();
    bool available();
   void Connexion(quint16 port);


signals:

public slots:
    float readyRead();
    float transmit();


private :

     QTcpSocket *_socket ;

     float _lastValue ;
     qint16 _port ;



};

#endif // SOCKETDATARECEIVER_H
