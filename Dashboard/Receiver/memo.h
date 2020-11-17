#ifndef MEMO_H
#define MEMO_H

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>

#include <QFile>
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
    QString fileName = "./memoTraining";
    QFile memoFile;
    QTextStream memoWrite;

    float getTimeMemo();

public slots:
    void initFile(float);
    void updateFile(float,float,float);
    void updateTimeMemo();

private:

    int cptFile=0;
    int cptTraining=1;

    float valTimeMemo;



};

#endif // MEMO_H
