#include "tendance.h"

tendance::tendance(QObject *parent):QObject(parent)
{

}

void tendance::initTendance(float val)
{
    detectChange=val;
}


int tendance::calcTendance(float val_actu, float val_memo)
{

    if(val_actu>val_memo+detectChange)
        Tendance=2;
    else if (val_actu<val_memo-detectChange)
        Tendance=0;
    else
        Tendance=1;

    return Tendance;
}
