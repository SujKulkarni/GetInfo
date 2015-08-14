#ifndef MYSYSINFO_H
#define MYSYSINFO_H

#include<QByteArray>
class mySysInfo
{
private:

    QByteArray arrSysData;

public:
          void setData( QByteArray arrData );
          QByteArray getData( void );
          mySysInfo();  // This is the constructor

};


#endif // MYSYSINFO_H
