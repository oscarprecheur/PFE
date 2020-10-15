#include <QCoreApplication>
#include "ServerBoussole.h"
#include "ServerGPS.h"
#include "serveraccelero.h"
#include "serverdirvent.h"
#include "servervitvent.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerBoussole serverBoussole(65431) ;
    //ServerGPS GPS(65433);
    ServerAccelero serverAccelero(65434);
    ServerDirVent serverVitVent(65435);
    //ServerVitVent VitVent(65436);




   return a.exec();
}
