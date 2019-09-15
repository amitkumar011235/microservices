#ifndef EXPOSED_H
#define EXPOSED_H
#include <QtCore>
#include <iostream>

#if defined MIDDLEWARE
 #define MIDDLE_COMMON_DLLSPEC Q_DECL_EXPORT
#else
 #define MIDDLE_COMMON_DLLSPEC Q_DECL_IMPORT
#endif


extern "C"
{
 MIDDLE_COMMON_DLLSPEC int  AddFromExe (int a , int b);
}




#endif // EXPOSED_H
