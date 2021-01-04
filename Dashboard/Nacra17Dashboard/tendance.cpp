#include "tendance.h"

tendance::tendance(QObject *parent):QObject(parent)
{

}

void tendance::initTendance(float val)
{
    detectChange=val;

    for(int a=0;a<100;a++)
        tab_val[a]=0;
}


int tendance::calcTendance(float val_actu)
{

    //FIFO de moyennage
    for(int a=99;a>=0;a--)
    {
        tab_val[a+1]=tab_val[a];

    }
        tab_val[0]=val_actu;
    //qDebug()<<tab_val[0]<<"       "<<tab_val[99];
    moyennage();
    //qDebug()<<"acumoy   "<<actuMoy<<"    memomoy "<<memoMoy;
    if (tab_val[0]>tab_val[99])
        Tendance=2;
    else if(tab_val[0]<tab_val[99])
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
    for(ind=0;ind<100;ind++)
        sum=sum+tab_val[ind];

    actuMoy=sum/100;
    //qDebug()<<"acumoy   "<<actuMoy;
}
