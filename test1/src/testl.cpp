#include <iostream>
#include "testl.h"
#include "exposed.h"

using namespace std;


int Add (int a , int b)
{
    return a+b;
}

void JustCheck ()
{
    int ret = AddFromExe (2,3);
    cout<<"res : "<<ret<<endl;
}

void Initialize ()
{
    cout<<"inside dll initilaize func.\n";
    int ret = AddFromExe (2,3);
    cout<<"got the value from AddFromExe :  "<<ret<<endl;
    cout<<"going out of initialize code\n";
}
