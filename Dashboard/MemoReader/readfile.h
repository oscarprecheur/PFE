#ifndef READFILE_H
#define READFILE_H

#include <QFileDialog>


class readfile: public QObject
{
    Q_OBJECT

public:

    readfile(QObject *parent = nullptr);

     Q_INVOKABLE void setFileUrl(QString NewFileUrl);
     Q_INVOKABLE void readFileLine(int nLine);

public slots:

private:
    QFileDialog dialog;
    QString FileUrl;
    QDir FileDir;
    QFile memoFile;
    int valtest;
};

#endif // READFILE_H
