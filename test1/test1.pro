QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = lib

DEFINES += TEST

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/testl.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/testl.h \


INCLUDEPATH += ../middleware/


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-webserver-Desktop_Qt_5_13_0_MinGW_64_bit-Debug/release/ -lwebserver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-webserver-Desktop_Qt_5_13_0_MinGW_64_bit-Debug/debug/ -lwebserver
else:unix: LIBS += -L$$PWD/../build-webserver-Desktop_Qt_5_13_0_MinGW_64_bit-Debug/ -lwebserver

INCLUDEPATH += $$PWD/../build-webserver-Desktop_Qt_5_13_0_MinGW_64_bit-Debug/debug
DEPENDPATH += $$PWD/../build-webserver-Desktop_Qt_5_13_0_MinGW_64_bit-Debug/debug
