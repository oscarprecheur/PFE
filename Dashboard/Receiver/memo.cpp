#include "memo.h"

memo::memo(QObject *parent):QObject(parent)
{

}

void memo::initFile(float deltaTime)
{
    //delta ecriture
    deltaTMemo=deltaTime;


    if (memoFile.exists(fileName))
    {
        qDebug()<<"ce fichier existe deja";
        memoFile.setFileName(fileName+QString::number(cptTraining)+".txt");
    }
    else
    {
        qDebug()<<"Ce fichier n'existe pas encore";
        memoFile.setFileName(fileName+".txt");
    }

    memoWrite.setDevice(&memoFile);
    if (memoFile.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"Fichier "<<memoFile.fileName()<<" ouvert";
    else
        qDebug()<<"Erreur fichier "<<memoFile.fileName();

}

void memo::updateFile(float gite, float tangage, float vitesse)
{
    qDebug()<<"1";

    memoWrite<<" T:"<<getTimeMemo()<<"/AnglePitch:"<<gite<<"/AngleRoll:"<<tangage<<"/ValInstSpeed:"<<vitesse<<"\n";
    cptFile++;
}

void memo::updateTimeMemo()
{
    valTimeMemo=cptFile*(deltaTMemo/1000);
//    qDebug()<<cptFile;
//    qDebug()<<valTimeMemo;
//    qDebug()<<deltaTMemo;
}

int memo::getcptFile()
{
    return cptFile;
}

float memo::getTimeMemo()
{
    return valTimeMemo;
}
