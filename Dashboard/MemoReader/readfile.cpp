#include "readfile.h"
#include <QDebug>
#include <QApplication>

readfile::readfile(QObject *parent):QObject(parent)
{

}

void readfile::setFileUrl(QString NewFileUrl)
{
    if (NewFileUrl.contains("file:///"))
            NewFileUrl.replace("file:///","");
    qDebug()<<"Debug SetFileUrl1"<<NewFileUrl;
    FileUrl=NewFileUrl;
    qDebug()<<"Debug SetFileUrl2"<<FileUrl;

    readFileLine(4);
}

void readfile::readFileLine(int nLine)
{

//    if (FileDir.exists(FileUrl))
//    {
//        qDebug()<<"Ce dossier existe";
//    }
//    else
//    {
//        qDebug()<<"Ce dossier n'existe pas ";
//    }

    memoFile.setFileName(FileUrl);
   if (!memoFile.open(QIODevice::ReadOnly | QIODevice::Text))
       qDebug()<<"ok";
   else
       qDebug()<<"opened";
}
