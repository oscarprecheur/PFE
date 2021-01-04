#ifndef SERVERSENSOR_H
#define SERVERSENSOR_H


#include <QObject>
#include <QString>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include<QTimer>

class serversensor : public QObject
{
    Q_OBJECT
public:
   explicit serversensor(quint16 port, QString nameSensor, QObject *parent=nullptr);
bool isconnected=false;


public slots:
    void newConnection();
    void bytesWritten(qint64);


    void update(float);



private:
    QTcpServer *_server ;
    QTcpSocket *_socket ;

    void startStreamingData();
    QByteArray a;
};
#endif // SERVERSENSOR_H
