#ifndef MEMO_H
#define MEMO_H

#include <QObject>
#include <QtWidgets>

#include <QFile>
#include <QDir>

#include <QString>
#include <QTextStream>
#include <QDate>
#include <QTime>



class memo: public QObject
{
    Q_OBJECT
public:
    memo(QObject*parent = nullptr);

    float deltaTMemo; //fréquence de memorisation en ms

    int getcptFile();
    QString fileName;//nom du fichier
    QString dirName = "./training_saves";//nom du repertoire
    QFile memoFile; //fichier en question
    QDir memoDir;//repertoire en question
    QTextStream memoWrite;// chain de caractère permettant l'écriture dans le fichier
    QDate date;
    QTime time;

    float getTimeMemo();//valeur du temps actuel

public slots:
    void initFile(float,float,float,float,float,float); //initialisation du fichier
    void initTimeMemo();//initialisation de la valeur de temps
    void updateFile(float,float,float,float,int,int,int);//MAJ des donnes dans le fichier
    void updateTimeMemo();//MAJ de la valure de temps

private:

    int cptFile=0;//compteur de lignes du fichier
    int cptTraining=1;

    float valTimeMemo;//valeur du temps acutel
    int cptLigneData =0;//compteur du nombre de ligne de données du fichier



};

#endif // MEMO_H
