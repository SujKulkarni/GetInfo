#include "mysysinfo.h"
#include<QDebug>

mySysInfo::mySysInfo()
{

   qDebug() << "Object is being created" << endl;
}

void mySysInfo::setData( QByteArray arrData )
{
         arrSysData = arrData;
}

QByteArray mySysInfo::getData( void )
{
        return arrSysData;
}



