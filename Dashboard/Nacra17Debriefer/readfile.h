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

    //méthode invocable par le composant QML
     Q_INVOKABLE void setFileUrl(QString NewFileUrl);
     Q_INVOKABLE void readFileLineData(int);
     Q_INVOKABLE void loadAllFile();
     Q_INVOKABLE QString readDataFile(int,int);
     Q_INVOKABLE void initReading();
     Q_INVOKABLE bool openFile();
     Q_INVOKABLE void closeFile();

    //Propriété invocables par le composant QML
    Q_PROPERTY(float getValMemoTempo READ getValMemoTempo CONSTANT)
    Q_PROPERTY(float getValTangageSeuilMax READ getValTangageSeuilMax CONSTANT)
    Q_PROPERTY(float getValTangageSeuilMin READ getValTangageSeuilMin CONSTANT)
    Q_PROPERTY(float getValGiteSeuilMax READ getValGiteSeuilMax CONSTANT)
    Q_PROPERTY(float getValGiteSeuilMin READ getValGiteSeuilMin CONSTANT)
    Q_PROPERTY(float getValTime READ getValTime CONSTANT)
    Q_PROPERTY(float getValDistance READ getValDistance CONSTANT)
    Q_PROPERTY(float getValTangageVal READ getValTangageVal CONSTANT)
    Q_PROPERTY(float getValTangageTend READ getValTangageTend CONSTANT)
    Q_PROPERTY(float getValGiteVal READ getValGiteVal CONSTANT)
    Q_PROPERTY(float getValGiteTend READ getValGiteTend CONSTANT)
    Q_PROPERTY(float getValVitesseVal READ getValVitesseVal CONSTANT)
    Q_PROPERTY(float getValVitesseTend READ getValVitesseTend CONSTANT)
    Q_PROPERTY(int getNbDataLine READ getNbDataLine CONSTANT)

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
    //nombre de données
    int getNbDataLine();

public slots:

private:

    QString DataFile;
    QStringList listLineDataFile;
    QStringList listCaseDataFile;

    QFileDialog dialog;
    QString FileUrl;
    QDir FileDir;
    QFile memoFile;
    int valtest;



    int nbDataLine=0;

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
    float time=0;
    //distance
    float distance=0;
    //tangage
    float tangageVal=0;
    //tend tangage
    float tangageTend=0;
    //gite
    float giteVal=0;
    //tend gite
    float giteTend=0;
    //vitesse
    float vitesseVal=0;
    //tend vitesse
    float vitesseTend=0;

    //-------------à faire-----------
    //vitesse moy 500
    //vitesse moy 10 sec
    //direction
    //latitude
    //longitude
    //-------------------------------

};

#endif // READFILE_H
