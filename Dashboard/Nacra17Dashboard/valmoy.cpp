#include "valmoy.h"

//début d'etude du moyennage des données vitesse mais ne focntionne pas

valmoy::valmoy(QObject *parent):QObject(parent)
{

}

void valmoy::addData(float dist,float vitesse)
{
    qDebug()<<TabData.size();
    if(!TabData.isEmpty())
    {
        TabData.resize(TabData.size()+1);

        for(int ind=TabData.size();ind>0;ind--)
        {
            TabData[ind].insert(0,TabData[ind-1].value(0));
            TabData[ind].insert(1,TabData[ind-1].value(1));
        }

        TabData[0].insert(0,dist);
        TabData[0].insert(1,vitesse);
        qDebug()<<TabData[0].value(1);
        qDebug()<<TabData[0].value(0);

    }
    else
    {
    TabData.resize(TabData.size()+1);

    TabData[0].insert(0,dist);
    TabData[0].insert(1,vitesse);
    qDebug()<<TabData[0].value(1);
    qDebug()<<TabData[0].value(0);
    }

}















































/*
                                                        ¶¶
                                                       ¶¶¶¶
                                                      ¶¶¶¶¶¶
                                                     ¶¶¥¥¥¶¶¶
                                                    ¶¶¥¥¥¥¥¶¶¶                                          ¶¶¶¶¶¶¶¶
                                                    ¶¶¥¥¥¥¥¥¶¶¶                                     ¶¶¶¶¶¥¥¥¥¥¶¶
                                                    ¶¶¥¥¥¥¥¥ƒƒ¶¶                                ¶¶¶¶¥¥¥¥¥¥¥¥¶¶¶¶
                                                    ¶¶¥¥¥¥ƒƒƒƒƒ¶¶                           ¶¶¶¶ƒƒ¥¥¥¥¥¥¥¥¶¶¶¶
                                                    ¶¶¶ƒƒƒƒƒƒƒƒ§¶¶                        ¶¶ƒƒƒƒƒƒƒ¥¥¥¥¥¶¶¶¶
                                                     ¶¶¶ƒƒƒƒƒƒ§§¶¶                    ¶¶¶¶ƒƒƒƒƒƒƒƒƒƒ¥¥¶¶¶¶
                                                       ¶¶ƒƒƒƒƒ§§¶¶                  ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒ¶¶¶¶
                                                        ¶¶ƒƒ§§§§¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§¶¶
                                                         ¶¶§§§§§§§ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§¶¶
                                                          ¶¶§§§ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§¶¶¶¶                   ¶¶¶¶¶¶
                                                        ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§¶¶¶                    ¶¶¶ƒƒƒƒƒ¶¶
                                                      ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ¶¶¶¶¶¶ƒƒƒƒ§§§¶¶¶                   ¶¶ƒƒƒƒƒƒƒƒ¶¶
                                                     ¶¶ƒƒ¶¶¶¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒ¶¶  ¶¶¶¶ƒƒƒ§§§§§¶¶                ¶¶ƒƒƒƒƒƒƒƒƒƒ¶¶
                                                    ¶¶ƒƒ¶¶  ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒ¶¶¶¶¶¶¶¶ƒƒƒ§§§§§§¶¶           ¶¶¶¶ƒƒƒƒƒƒƒƒ§§§§§§¶¶
                                                   ¶¶ƒƒƒ¶¶¶¶¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ¶¶¶¶¶¶ƒƒƒƒƒ§§§§§§¶¶        ¶¶ƒƒƒƒƒƒƒƒ§§§§§§§§§§¶¶
                                                   ¶¶ƒƒƒƒ¶¶¶¶ƒƒƒƒƒ¥¥¥ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ####§§§§§¶¶    ¶¶¶¶ƒƒƒƒƒƒƒƒ§§§§§§§§§§§§¶¶
                                                   ¶¶###ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ¥¥ƒƒƒƒƒƒ########§§§§¶¶¶¶¶¶ƒƒƒƒƒƒƒƒ§§§§§§§§§§§§§§§§¶¶
                                                   ¶¶####ƒƒƒƒƒƒƒƒ¥¥¥¥¥¥¥¥¥¥¥ƒƒƒƒƒƒ########§§¶¶¶¶ƒƒ¶¶¶¶ƒƒƒƒ§§§§§§§§§§§§§§§§§§¶¶
                                                ¶¶¶¶¶¶###ƒƒƒƒƒƒƒƒƒ¥¥¥#####¥ƒƒƒƒƒƒƒ########¶¶ƒƒ¶¶ƒƒƒƒƒƒ¶¶§§§§§§§§§§§§§§§§§§§§¶¶
                                              ¶¶¶ƒƒ¶¶¶¶#ƒƒƒƒƒƒƒƒƒƒ¥¥####¥¥ƒƒƒƒƒƒƒƒƒƒ####§§¶¶ƒƒƒƒƒƒƒƒ¶¶¶¶§§§§§§§§§§§§§§§§¶¶¶¶
                                             ¶¶ƒƒ¶ƒƒƒƒ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒ¥¥¥¥ƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§¶¶ƒƒƒƒƒƒƒƒƒƒƒƒ¶¶§§§§§§§§§§§§¶¶¶¶
                                            ¶¶ƒƒƒƒƒƒ§§§§¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ¶¶ƒƒƒƒƒƒƒƒ§§§§¶¶§§§§§§§§§§¶¶¶¶
                                              ¶¶ƒƒ§§§§§§¶¶¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§¶¶¶§§§§§§§§¶¶
                                                ¶¶§§§§§§§¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§¶  ¶§§§§§§¶¶
                                                  ¶¶§§§§§§ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§¶¶    ¶¶§§§§§§¶¶
                                                    ¶¶¶§ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§¶¶       ¶¶§§§§§§¶¶
                                                     ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§¶¶¶¶    ¶¶¶¶§§§§§§§§§§¶¶
                                                     ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§¶¶§§¶¶¶¶¶¶ƒƒ§§§§§§§§¶¶¶¶
                                                    ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§§¶¶ƒƒƒƒ§§§§§§¶¶¶¶
                                                    ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§§§¶¶§§§§§§§¶¶¶¶
                                              ¶¶¶¶¶¶¶¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§§§§¶¶§§§§§§¶¶
                                             ¶¶ƒƒ¶¶ƒƒƒ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§§§§¶¶¶¶§§§§§§¶¶
                                             ¶¶ƒƒƒ¶¶ƒƒƒ¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§§§§§¶¶  ¶¶¶###§§§¶¶
                                              ¶¶§§§§§§§§¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§§§§§§§§¶¶¶¶¶#######§§§¶¶
                                               ¶¶§§§§§§§§¶¶ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒ§§§§§§§§§§§§§§§§§########¶¶¶¶¶¶
                                                ¶¶§§§§§§§§¶¶§§§§ƒƒƒƒƒƒƒ§§§§§§§§§§§§§§§§§§§####¶¶¶¶¶¶
                                                 ¶¶§§§§§§§¶¶§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§¶¶¶¶
                                                   ¶¶¶¶¶¶¶§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§¶¶
                                                          ¶¶¶¶¶¶¶¶¶¶§§§§§§§§§§§§§§§§§§§§¶¶
                                                                    ¶¶¶¶¶¶§§§§§§§§§§¶¶¶¶
                                                                        ¶¶¶¶§§§§¶¶¶¶¶
                                                                        ¶¶§§§§§§§§¶¶
                                                                        ¶¶§§¶¶§§§¶¶
                                                                         ¶¶§¶¶§§¶¶
                                                                          ¶¶¶¶¶¶
*/