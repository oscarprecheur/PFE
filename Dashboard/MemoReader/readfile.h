#ifndef READFILE_H
#define READFILE_H

#include <QFileDialog>
#include <QDate>
#include <QTime>


class readfile: public QObject
{
    Q_OBJECT

public:

    readfile(QObject *parent = nullptr);

     Q_INVOKABLE void setFileUrl(QString NewFileUrl);
     Q_INVOKABLE void readFileLineData(int);
     Q_INVOKABLE void initReading();

public slots:

private:

    QString line;
    QStringList listLineValue;
    QFileDialog dialog;
    QString FileUrl;
    QDir FileDir;
    QFile memoFile;
    int valtest;

    bool openFile();

    //valeurs données

    //date
    QDate fileDate;
    //heure
    QTime fileTime;
    //tempo
    float memoTempo;
    //seuils tang
    float tangageSeuilMax;
    float tangageSeuilMin;
    //seuils gite
    float giteSeuilMax;
    float giteSeuilMin;
    //temps
    float time;
    //distance
    float distance;
    //tangage
    float tangageVal;
    //tend tangage
    float tangageTend;
    //gite
    float giteVal;
    //tend gite
    float giteTend;
    //vitesse
    float vitesseVal;
    //tend vitesse
    float vitesseTend;

    //-------------à faire-----------
    //vitesse moy 500
    //vitesse moy 10 sec
    //direction
    //latitude
    //longitude
    //-------------------------------

};

#endif // READFILE_H
