#ifndef TENDANCE_H
#define TENDANCE_H

#include <QObject>


class tendance:public QObject
{

    Q_OBJECT
public:
    tendance(QObject *parent = nullptr);
    void initTendance(float);
    void moyennage();

public slots:
    int calcTendance(float);

private:
    int Tendance=1;
    float detectChange;
    float tab_val[10];
    float newval;
    float memoMoy;
    float actuMoy;
    float sum;

};

#endif // TENDANCE_H
