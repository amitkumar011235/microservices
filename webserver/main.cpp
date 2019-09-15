#include <QCoreApplication>
#include <QtGlobal>
#include <QTimer>
#include <QLibrary>
#include <iostream>
#include <QSettings>
#include <QFile>
#include <QDir>
#include "webserverutil.h"
#include "httplistener.h"
#include "httprequesthandler.h"
#include "helloworldcontroller.h"
#include "requestmapper.h"


using namespace std;
using namespace stefanfrings;




/**
 * Search the configuration file.
 * Aborts the application if not found.
 * @return The valid filename
 */
QString searchConfigFile() {
    QString binDir=QCoreApplication::applicationDirPath();
    QString appName=QCoreApplication::applicationName();
    QFile file;
    file.setFileName(binDir+"/webapp1.ini");
    if (!file.exists()) {
        file.setFileName(binDir+"/etc/webapp1.ini");
        if (!file.exists()) {
            file.setFileName(binDir+"/../etc/webapp1.ini");
            if (!file.exists()) {
                file.setFileName(binDir+"/../"+appName+"/etc/webapp1.ini");
                if (!file.exists()) {
                    file.setFileName(binDir+"/../../"+appName+"/etc/webapp1.ini");
                    if (!file.exists()) {
                        file.setFileName(binDir+"/../../../../../"+appName+"/etc/webapp1.ini");
                        if (!file.exists()) {
                            file.setFileName(QDir::rootPath()+"etc/webapp1.ini");
                        }
                    }
                }
            }
        }
    }
    if (file.exists()) {
        QString configFileName=QDir(file.fileName()).canonicalPath();
        qDebug("using config file %s", qPrintable(configFileName));
        return configFileName;
    }
    else {
        qFatal("config file not found");
    }
}





int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    //    qDebug("start");

    //    QTimer *timer = new QTimer();
    //    QObject::connect(timer, SIGNAL(timeout()), &app, SLOT(quit()));
    //    timer->start(2000);

    //    qDebug("entering the event loop");

    //    QTimer *timer  = new QTimer();
    //    QObject::connect(timer,SIGNAL(timeout()), &app, SLOT(quit()));
    //    timer->start(2000);



    // Load the configuration file
    QString configFileName=searchConfigFile();
    QSettings* listenerSettings=new QSettings(configFileName, QSettings::IniFormat, &app);
    qDebug("config file loaded");

    listenerSettings->beginGroup("listener");

    //read the service file to load
    QString lib_path =  listenerSettings->value("path").toString();

    //start the http server
    new HttpListener(listenerSettings, new RequestMapper(&app), &app);










    //calling dll function
    QLibrary libtest(lib_path);
    if (!libtest.load())
    {
        const char *err_str = (libtest.errorString().toLatin1().data());
        printf("%s", err_str);
    }
    else {
        cout<<"test library successfully loaded\n";
    }

    typedef void (*AddFunc)();
    AddFunc func = (AddFunc)libtest.resolve("Initialize");
    if (func){
        cout<<"got the func name\n";
        func();
    }
    else {
        cout<<"cannot get the func name\n";
    }


    return app.exec();
}
