#ifndef TESTL_H
#define TESTL_H
//#include <QtCore>
#include <iostream>


#if defined TEST
 #define TEST_COMMON_DLLSPEC __declspec(dllexport)
#else
 #define TEST_COMMON_DLLSPEC __declspec(dllimport)
#endif


extern "C"
{
TEST_COMMON_DLLSPEC int Add (int a , int b);
TEST_COMMON_DLLSPEC void Initialize ();
}




#endif // TESTL_H
