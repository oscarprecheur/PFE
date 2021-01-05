#ifndef VALMOY_H
#define VALMOY_H

#include <QVector>
#include<QObject>
#include <QDebug>


class valmoy:public QObject
{

    Q_OBJECT

public:
    valmoy(QObject *parent = nullptr);
    void addData(float,float);
    void deleteData();
    void moyValue();

//public slots:
//    void calcmoy();

private:


    QVector<QVector<float>>TabData; //distance colonne 0 / vitesse colonne 1

};
#endif // VALMOY_H
