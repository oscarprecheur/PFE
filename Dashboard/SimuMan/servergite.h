#ifndef SERVERGITE_H
#define SERVERGITE_H


#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class servergite : public QObject
{
    Q_OBJECT
public:
   explicit servergite(quint16 port, QObject *parent=nullptr);


signals:
    void cptchange();

public slots:
    void newConnection();
    void bytesWritten(qint64);


    void update(int);
    void updatecpt();


private:
    QTcpServer *_server ;
    QTcpSocket *_socket ;

    void startStreamingData();
    float getNextValue();
    float cpt=1;
    QByteArray a;
};
#endif // SERVERGITE_H
