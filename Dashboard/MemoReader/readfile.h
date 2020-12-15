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

    Q_PROPERTY(float getValMemoTempo READ getValMemoTempo)
    Q_PROPERTY(float getValTangageSeuilMax READ getValTangageSeuilMax)
    Q_PROPERTY(float getValTangageSeuilMin READ getValTangageSeuilMin)
    Q_PROPERTY(float getValGiteSeuilMax READ getValGiteSeuilMax)
    Q_PROPERTY(float getValGiteSeuilMin READ getValGiteSeuilMin)
    Q_PROPERTY(float getValTime READ getValTime)
    Q_PROPERTY(float getValDistance READ getValDistance)
    Q_PROPERTY(float getValTangageVal READ getValTangageVal)
    Q_PROPERTY(float getValTangageTend READ getValTangageTend)
    Q_PROPERTY(float getValGiteVal READ getValGiteVal)
    Q_PROPERTY(float getValGiteTend READ getValGiteTend)
    Q_PROPERTY(float getValVitesseVal READ getValVitesseVal)
    Q_PROPERTY(float getValVitesseTend READ getValVitesseTend)


    float getValMemoTempo();
    //seuils tang
    float getValTangageSeuilMax();
    float getValTangageSeuilMin();
    //seuils gite
    float getValGiteSeuilMax();
    float getValGiteSeuilMin();
    //temps
    float getValTime();
    //distance
    float getValDistance();
    //tangage
    float getValTangageVal();
    //tend tangage
    float getValTangageTend();
    //gite
    float getValGiteVal();
    //tend gite
    float getValGiteTend();
    //vitesse
    float getValVitesseVal();
    //tend vitesse
    float getValVitesseTend();

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

    int nbFileLine;

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
