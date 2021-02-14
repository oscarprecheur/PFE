#include "tendance.h"

tendance::tendance(QObject *parent):QObject(parent)
{

}

void tendance::initTendance(float val)
{
    detectChange=val;

    for(int a=0;a<100;a++)//inititialisation de la FIFO à 0
        tab_val[a]=0;
}


int tendance::calcTendance(float val_actu)
{

    //FIFO de moyennage
    for(int a=99;a>=0;a--)//on décale toute les données vers le bas, la données la plus encienne est supprimée
    {
        tab_val[a+1]=tab_val[a];

    }
        tab_val[0]=val_actu;//on ajoute la nouvelle données
    //qDebug()<<tab_val[0]<<"       "<<tab_val[99];
    moyennage();//calcul de la vitesse moyenne
    //qDebug()<<"acumoy   "<<actuMoy<<"    memomoy "<<memoMoy;
    if (tab_val[0]>tab_val[99])//on compare les données extreme [0] et [99]
        Tendance=2;//augmente
    else if(tab_val[0]<tab_val[99])
        Tendance=0;//stagne
    else
        Tendance=1;//diminue

    memoMoy=actuMoy;


    return Tendance;
}


void tendance::moyennage()//calcue de la vitesse moyenne (pas utilisé)
{
    sum=0;
    int ind;
    for(ind=0;ind<100;ind++)
        sum=sum+tab_val[ind];

    actuMoy=sum/100;
    //qDebug()<<"acumoy   "<<actuMoy;
}
