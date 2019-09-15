QT += core
QT -= gui
QT += network



OTHER_FILES += etc/webapp1.ini

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

DEFINES += WEBSERVER

DEFINES += MIDDLEWARE


#Adding .lib file while creating .exe so it can be used while creating .dll file.
#LDFLAGS += -Wl,--out-implib,C:/Users/kumaramit/Desktop/my_proj_info/qt_proj/build-webserver-Desktop_Qt_5_13_0_MinGW_64_bit-Debug/debug/webserver.a
QMAKE_LFLAGS += -Wl,--out-implib,C:/Users/kumaramit/Desktop/my_proj_info/qt_proj/build-webserver-Desktop_Qt_5_13_0_MinGW_64_bit-Debug/debug/libwebserver.a

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../middleware/exposed.cpp \
        helloworldcontroller.cpp \
        listdatacontroller.cpp \
        main.cpp \
        requestmapper.cpp \
        webserverutil.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../middleware/exposed.h \
    helloworldcontroller.h \
    listdatacontroller.h \
    requestmapper.h \
    webserverutil.h \


include(../QtWebApp/QtWebApp/httpserver/httpserver.pri)
#include (C:/Users/kumaramit/Desktop/my_proj_info/qt_proj/QtWebApp/QtWebApp/httpserver)
