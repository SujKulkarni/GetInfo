#include <QApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include<QProcess>
#include<QDebug>
#include "mysysinfo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString commands;
    //Mac specific Terminal command
     commands = "system_profiler SPHardwareDataType";

     //commands = "cat abc"; /* Wrong cat file -- testing */
    //commands = " abc";   /* Wrong Terminal command -- testing */


    /* For Linux and Ubuntu we use  --  cat /proc/cpuinfo*/

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


        QProcess *process = new QProcess(0);
        process->setProcessChannelMode(QProcess::MergedChannels);
        //process->start("system_profiler SPHardwareDataType");

        process->start(commands);
        QByteArray arrSysInfo;

        process->write(arrSysInfo);
        process->closeWriteChannel();


         if(!process->waitForStarted()){
            qDebug() << "Could not wait to start..."
                    << process->error()
                    << process->errorString();
        }

        if(!process->waitForFinished()) {
           qDebug() << "Could not wait to finish..."
           << process->error()
           << process->errorString();
        }
        else{

         mySysInfo output;  /*  interface */
         output.setData( process->readAll());

         QObject *rootObject = engine.rootObjects().first();


         QObject* lstview = rootObject->findChild<QObject*>("lstview");
         if (lstview)
             lstview->setProperty("placeholderText", output.getData());//quick fix

        }

     return app.exec();
}


