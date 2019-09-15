#ifndef EXPOSED_H
#define EXPOSED_H
#include <iostream>

#if defined MIDDLEWARE
 #define MIDDLE_COMMON_DLLSPEC __declspec(dllexport)
#else
 #define MIDDLE_COMMON_DLLSPEC __declspec(dllimport)
#endif


extern "C"
{
 __declspec(dllimport) int  AddFromExe (int a , int b);
}




#endif // EXPOSED_H
