#ifndef WEBSERVERUTIL_H
#define WEBSERVERUTIL_H
#include <iostream>

#if defined WEBSERVER
 #define WEBSERVER_COMMON_DLLSPEC __declspec(dllexport)
#else
 #define WEBSERVER_COMMON_DLLSPEC __declspec(dllimport)
#endif

extern "C"
{
int WEBSERVER_COMMON_DLLSPEC AddFromExeUtil (int a, int b);
}


#endif // WEBSERVERUTIL_H
