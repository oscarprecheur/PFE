#ifndef servervitesse_H
#define servervitesse_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class servervitesse : public QObject
{
    Q_OBJECT
public:
   explicit servervitesse(quint16 port, QObject *parent=nullptr);
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

#endif // servervitesse_H
