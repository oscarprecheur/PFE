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
    QString line;
    QStringList listLineValue;

    //date
    line = memoFile.readLine();
    listLineValue = line.split(";");
    fileDate.setDate(listLineValue.at(3).toInt(),listLineValue.at(2).toInt(),listLineValue.at(1).toInt());
    qDebug()<<fileDate;
}

void readfile::readFileLine(int nLine, int nColomn)
{
    openFile();
    QString finalVal;
    QString line;
    QStringList listeDeMots;
    for(int cpt=0;cpt<=nLine;cpt++)
    {
        line = memoFile.readLine();
        listeDeMots = line.split(";");
    }
    finalVal=listeDeMots.at(nColomn);
    qDebug()<<finalVal;

}
