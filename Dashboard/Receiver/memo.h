#ifndef MEMO_H
#define MEMO_H

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>

#include <QFile>
#include <QDir>

#include <QString>
#include <QTextStream>
#include <QDate>
#include <QTime>

#include <QMatrix>

class memo: public QObject
{
    Q_OBJECT
public:
    memo(QObject*parent = nullptr);

    float deltaTMemo; //fréquence de memorisation en ms

    int getcptFile();
    QString fileName;
    QString dirName = "./training_saves";
    QFile memoFile;
    QDir memoDir;
    QTextStream memoWrite;
    QDate date;
    QTime time;

    float getTimeMemo();

public slots:
    void initFile(float,float,float,float,float,float);
    void initTimeMemo();
    void updateFile(float,float,float,float,int,int,int);
    void updateTimeMemo();

private:

    int cptFile=0;
    int cptTraining=1;

    float valTimeMemo;



};

#endif // MEMO_H
