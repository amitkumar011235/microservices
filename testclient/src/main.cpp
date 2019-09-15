#include <QCoreApplication>
#include <iostream>
#include "testl.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"hello world\n";

    QLibrary libtest("test1");
    if (!libtest.load())
    {
        cout<<"test library cannt be loaded\n";
    }
    else {
        cout<<"test library successfully loaded\n";
    }

    typedef int (*AddFunc)(int, int);
    AddFunc func = (AddFunc)libtest.resolve("Add");
    if (func){
        cout<<"got the func name\n";
        cout<<"sum = "<<func(2,3)<<endl;
    }
    else {
        cout<<"cannot get the func name\n";
    }

    cout<<"end of program\n";
    return a.exec();
}
