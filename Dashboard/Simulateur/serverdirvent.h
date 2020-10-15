#ifndef ServerDirVent_H
#define ServerDirVent_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class ServerDirVent : public QObject
{
    Q_OBJECT
public:
   explicit ServerDirVent(quint16 port, QObject *parent=nullptr);


signals:
    void cptchange();

public slots:
    void newConnection();
    void bytesWritten(qint64);


    void update();
    void updatecpt();


private:
    QTcpServer *_server ;
    QTcpSocket *_socket ;

    void startStreamingData();
    float getNextValue();
    float cpt=1;
    QByteArray a;
};

#endif // ServerDirVent_H
