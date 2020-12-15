#include "readfile.h"
#include <QDebug>
#include <QApplication>

readfile::readfile(QObject *parent):QObject(parent)
{

}

void readfile::setFileUrl(QString NewFileUrl)
{
    FileUrl=NewFileUrl;
    qDebug()<<"Debug SetFileUrl"<<FileUrl;
}

void readfile::readFileLine(int nLine)
{
    if (FileDir.exists(FileUrl))
    {
        qDebug()<<"Ce dossier existe";
    }
    else
    {
        qDebug()<<"Ce dossier n'existe pas ";
    }
}
