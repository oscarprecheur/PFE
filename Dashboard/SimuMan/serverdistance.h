#ifndef SERVERDISTANCE_H
#define SERVERDISTANCE_H


#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class serverdistance : public QObject
{
    Q_OBJECT
public:
   explicit serverdistance(quint16 port, QObject *parent=nullptr);


public slots:
    void newConnection();
    void bytesWritten(qint64);


    void update(int);


private:
    QTcpServer *_server ;
    QTcpSocket *_socket ;

    void startStreamingData();

   QByteArray a;
};
#endif // SERVERGITE_H
