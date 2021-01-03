#ifndef SERVERTANGAGE_H
#define SERVERTANGAGE_H


#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class servertangage : public QObject
{
    Q_OBJECT
public:
   explicit servertangage(quint16 port, QObject *parent=nullptr);
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
#endif // SERVERTANGAGE_H
