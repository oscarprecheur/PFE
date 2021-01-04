#ifndef SERVERDISTANCE_H
#define SERVERDISTANCE_H


#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include<QTimer>


class serverdistance : public QObject
{
    Q_OBJECT
public:
   explicit serverdistance(quint16 port, QObject *parent=nullptr);
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
#endif // SERVERGITE_H
