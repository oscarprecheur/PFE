#include "memo.h"

memo::memo(QObject *parent):QObject(parent)
{

}

void memo::initFile(float deltaTime)
{
    //delta ecriture
    deltaTMemo=deltaTime;
    time = time.currentTime();
    date = date.currentDate();



    if (memoFile.exists(fileName+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+"_"+QString::number(time.hour())+"h"+QString::number(time.minute())+"m"+QString::number(time.second())+"s"+".txt"))
    {
        qDebug()<<"ce fichier existe deja";
        memoFile.setFileName(fileName+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+"_"+QString::number(time.hour())+"h"+QString::number(time.minute())+"m"+QString::number(time.second())+"s"+".txt");
    }
    else
    {
        qDebug()<<"Ce fichier n'existe pas encore";
        memoFile.setFileName(fileName+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+"_"+QString::number(time.hour())+"h"+QString::number(time.minute())+"m"+QString::number(time.second())+"s"+".txt");
    }

    memoWrite.setDevice(&memoFile);
//    if (memoFile.open(QIODevice::WriteOnly | QIODevice::Text))
//        qDebug()<<"Fichier "<<memoFile.fileName()<<" ouvert";
//    else
//        qDebug()<<"Erreur fichier "<<memoFile.fileName();

}

void memo::updateFile(float gite, float tangage, float vitesse)
{
    memoFile.open(QIODevice::WriteOnly |QIODevice::Append| QIODevice::Text);
    memoWrite<<" T:"<<getTimeMemo()<<"/AnglePitch:"<<gite<<"/AngleRoll:"<<tangage<<"/ValInstSpeed:"<<vitesse<<"\n";
    cptFile++;
    memoFile.close();
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
