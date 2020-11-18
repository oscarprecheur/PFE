#include "tendance.h"
#include <QDebug>

tendance::tendance(QObject *parent):QObject(parent)
{

}

void tendance::initTendance(float val)
{
    detectChange=val;

    for(int a=0;a<10;a++)
        tab_val[a]=0;
}


int tendance::calcTendance(float val_actu)
{

    //FIFO de moyennage
    for(int a=0;a<9;a++)
    {
        tab_val[a+1]=tab_val[a];

    }
        tab_val[0]=val_actu;

    moyennage();
    //qDebug()<<"acumoy   "<<actuMoy<<"    memomoy "<<memoMoy;
    if (actuMoy>memoMoy)
        Tendance=2;
    else if(actuMoy<memoMoy)
        Tendance=0;
    else
        Tendance=1;

    memoMoy=actuMoy;


    return Tendance;
}


void tendance::moyennage()
{
    sum=0;
    int ind;
    for(ind=0;ind<10;ind++)
        sum=sum+tab_val[ind];

    actuMoy=sum/10;
    qDebug()<<"acumoy   "<<actuMoy;
}
