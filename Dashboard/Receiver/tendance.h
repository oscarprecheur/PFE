#ifndef TENDANCE_H
#define TENDANCE_H

#include <QObject>


class tendance:public QObject
{

    Q_OBJECT
public:
    tendance(QObject *parent = nullptr);
    void initTendance(float);

public slots:
    int calcTendance(float,float);

private:
    int Tendance=1;
    float detectChange;

};

#endif // TENDANCE_H
