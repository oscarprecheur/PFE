#include "readfile.h"
#include <QDebug>
#include <QApplication>

readfile::readfile(QObject *parent):QObject(parent)
{

}

bool readfile::openFile()
{
    memoFile.setFileName(FileUrl);
   if (!memoFile.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       qDebug()<<"File"<<FileUrl<<"Not Opened";
       return false;
   }
   else
   {
       qDebug()<<"File"<<FileUrl<<" Opened";
       return true;
   }
}

void readfile::setFileUrl(QString NewFileUrl)
{
    if (NewFileUrl.contains("file:///"))
            NewFileUrl.replace("file:///","");
    qDebug()<<"Debug SetFileUrl1"<<NewFileUrl;
    FileUrl=NewFileUrl;
    qDebug()<<"Debug SetFileUrl2"<<FileUrl;

    initReading();
}

void readfile::initReading()
{

    openFile();


    //date
    line = memoFile.readLine();
    listLineValue = line.split(";");

    fileDate.setDate(listLineValue.at(3).toInt(),listLineValue.at(2).toInt(),listLineValue.at(1).toInt());

    qDebug()<<"Date :"<<fileDate;

    //heure
    line = memoFile.readLine();
    listLineValue = line.split(";");

    fileTime.setHMS(listLineValue.at(1).toInt(),listLineValue.at(2).toInt(),listLineValue.at(3).toInt());

    qDebug()<<"Heure :"<<fileTime;

    //tempo memo (ms)
    line = memoFile.readLine();
    listLineValue = line.split(";");

    memoTempo=listLineValue.at(1).toFloat();

    qDebug()<<"memoTempo (ms) :"<<memoTempo;

    //seuils
    line = memoFile.readLine();
    listLineValue = line.split(";");

    tangageSeuilMin=listLineValue.at(1).toFloat();
    tangageSeuilMax=listLineValue.at(2).toFloat();
    giteSeuilMin=listLineValue.at(3).toFloat();
    giteSeuilMax=listLineValue.at(4).toFloat();

    qDebug()<<"min tang :"<<tangageSeuilMin;
    qDebug()<<"max tang :"<<tangageSeuilMax;
    qDebug()<<"min gite :"<<giteSeuilMin;
    qDebug()<<"max gite:"<<giteSeuilMax;

    //readFileLineData(36);


}

void readfile::readFileLineData(int nLine)
{
    openFile();
    for(int cpt=0;cpt<=nLine+6;cpt++)
    {
        line = memoFile.readLine();
        listLineValue = line.split(";");
        qDebug()<<listLineValue;
    }

    //temps
    time=listLineValue.at(0).toFloat();
    qDebug()<<"time :"<<time;
    //distance
    distance=listLineValue.at(1).toFloat();
    qDebug()<<"distance :"<<distance;
    //tangage
    tangageVal=listLineValue.at(2).toFloat();
    qDebug()<<"tangageVal :"<<tangageVal;
    //tend tangage
    tangageTend=listLineValue.at(3).toFloat();
    qDebug()<<"tangageTend :"<<tangageTend;
    //gite
    giteVal=listLineValue.at(4).toFloat();
    qDebug()<<"giteVal :"<<giteVal;
    //tend gite
    giteTend=listLineValue.at(5).toFloat();
    qDebug()<<"giteTend :"<<giteTend;
    //vitesse
    vitesseVal=listLineValue.at(6).toFloat();
    qDebug()<<"vitesseVal :"<<vitesseVal;
    //tend vitesse
    vitesseTend=listLineValue.at(7).toFloat();
    qDebug()<<"vitesseTend :"<<vitesseTend;


}
