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

void readfile::closeFile()
{
    memoFile.close();
}

void readfile::setFileUrl(QString NewFileUrl)
{
    if (NewFileUrl.contains("file:///"))
            NewFileUrl.replace("file:///","");
    qDebug()<<"Debug SetFileUrl1"<<NewFileUrl;
    FileUrl=NewFileUrl;
    qDebug()<<"Debug SetFileUrl2"<<FileUrl;


}

void readfile::initReading()
{
    //nombre de ligne de données
    openFile();
    int cpt=0;
    while(!memoFile.atEnd())
    {
        memoFile.readLine();
        cpt++;
    }
    nbDataLine=cpt-5;
    closeFile();
    qDebug()<<"nombre ligne de donénes"<<nbDataLine;


    //date
    fileDate.setDate(readDataFile(3,0).toInt(),readDataFile(2,0).toInt(),readDataFile(2,0).toInt());

    qDebug()<<"Date :"<<fileDate;

    //heure
    fileTime.setHMS(readDataFile(1,1).toInt(),readDataFile(2,1).toInt(),readDataFile(3,1).toInt());

    qDebug()<<"Heure :"<<fileTime;

    //tempo memo (ms)

    memoTempo=readDataFile(1,2).toFloat();

    qDebug()<<"memoTempo (ms) :"<<memoTempo;

    //seuils

    tangageSeuilMin=readDataFile(1,3).toFloat();
    tangageSeuilMax=readDataFile(2,3).toFloat();
    giteSeuilMin=readDataFile(3,3).toFloat();
    giteSeuilMax=readDataFile(4,3).toFloat();

    qDebug()<<"min tang :"<<tangageSeuilMin;
    qDebug()<<"max tang :"<<tangageSeuilMax;
    qDebug()<<"min gite :"<<giteSeuilMin;
    qDebug()<<"max gite:"<<giteSeuilMax;
}

void readfile::readFileLineData(int nLine)
{

    //temps
    time=readDataFile(0,nLine+5).toFloat();
    qDebug()<<"time rvrv:"<<time;
    //distance
    distance=readDataFile(1,nLine+5).toFloat();
    qDebug()<<"distance :"<<distance;
    //tangage
    tangageVal=readDataFile(2,nLine+5).toFloat();
    qDebug()<<"tangageVal :"<<tangageVal;
    //tend tangage
    tangageTend=readDataFile(3,nLine+5).toFloat();
    qDebug()<<"tangageTend :"<<tangageTend;
    //gite
    giteVal=readDataFile(4,nLine+5).toFloat();
    qDebug()<<"giteVal :"<<giteVal;
    //tend gite
    giteTend=readDataFile(5,nLine+5).toFloat();
    qDebug()<<"giteTend :"<<giteTend;
    //vitesse
    vitesseVal=readDataFile(6,nLine+5).toFloat();
    qDebug()<<"vitesseVal :"<<vitesseVal;
    //tend vitesse
    vitesseTend=readDataFile(7,nLine+5).toFloat();
    qDebug()<<"vitesseTend :"<<vitesseTend;



}

void readfile::loadAllFile()
{
    openFile();
    DataFile = memoFile.readAll();
    nbDataLine = memoFile.size();
    closeFile();
}

QString readfile::readDataFile(int line, int colomn)
{
    listLineDataFile = DataFile.split("\n");
    listCaseDataFile=listLineDataFile.at(colomn).split(";");
    return listCaseDataFile.at(line);
}


//void readfile::readFileLineByLine()
//{



//    if (!memoFile.atEnd())
//        listLineDataFile = memoFile.readLine();
//    listLineValue = listLineDataFile.split(";");
//        //qDebug()<<listLineValue;

//    //temps
//    time=listLineValue.at(0).toFloat();
//    qDebug()<<"time :"<<time;
//    //distance
//    distance=listLineValue.at(1).toFloat();
//    qDebug()<<"distance :"<<distance;
//    //tangage
//    tangageVal=listLineValue.at(2).toFloat();
//    qDebug()<<"tangageVal :"<<tangageVal;
//    //tend tangage
//    tangageTend=listLineValue.at(3).toFloat();
//    qDebug()<<"tangageTend :"<<tangageTend;
//    //gite
//    giteVal=listLineValue.at(4).toFloat();
//    qDebug()<<"giteVal :"<<giteVal;
//    //tend gite
//    giteTend=listLineValue.at(5).toFloat();
//    qDebug()<<"giteTend :"<<giteTend;
//    //vitesse
//    vitesseVal=listLineValue.at(6).toFloat();
//    qDebug()<<"vitesseVal :"<<vitesseVal;
//    //tend vitesse
//    vitesseTend=listLineValue.at(7).toFloat();
//    qDebug()<<"vitesseTend :"<<vitesseTend;



//}



//------getter


float readfile::getValMemoTempo()
{
    return memoTempo;
}

float readfile::getValTangageSeuilMax()
{
    return tangageSeuilMax;
}

float readfile::getValTangageSeuilMin()
{
    return tangageSeuilMin;
}

float readfile::getValGiteSeuilMax()
{
    return giteSeuilMax;
}

float readfile::getValGiteSeuilMin()
{
    return giteSeuilMin;
}

float readfile::getValTime()
{
    return time;
}

float readfile::getValDistance()
{
    return distance;
}

float readfile::getValTangageVal()
{
    return tangageVal;
}

float readfile::getValTangageTend()
{
    return tangageTend;
}

float readfile::getValGiteVal()
{
    return giteVal;
}

float readfile::getValGiteTend()
{
    return giteTend;
}

float readfile::getValVitesseVal()
{
    return vitesseVal;
}

float readfile::getValVitesseTend()
{
    return vitesseTend;
}

int readfile::getNbDataLine()
{
    return nbDataLine;

}






