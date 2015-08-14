#include "mysysinfo.h"
#include<QDebug>

mySysInfo::mySysInfo()
{

   qDebug() << "Object is being created" << endl;
}

void mySysInfo::setData( QByteArray arrData )
{
   try{
         arrSysData = arrData;


    }
    catch(...){


    }

}



QByteArray mySysInfo::getData( void )
{
    try {
        return arrSysData;

    } catch (...) {
        return arrSysData;

    }

}



