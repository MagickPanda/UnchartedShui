#-------------------------------------------------
#
# Project created by QtCreator 2020-12-20T21:06:41
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UnchartedShuiServer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17
CONFIG += console

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        uslogger.cpp \
        ussocketserver.cpp \
        ustcpserver.cpp

HEADERS += \
        mainwindow.h \
        uslogger.h \
        usnetwork.h \
        usplatform.h \
        ussocketserver.h \
        ustcpserver.h

FORMS += \
        mainwindow.ui


inc_path = G:/dev_package/unchartedshui/x86/include
lib_path = G:/dev_package/unchartedshui/x86/lib-debug

log4qt_inc = G:/dev_package/unchartedshui/x86/log4qt/include/
log4qt_lib = G:/dev_package/unchartedshui/x86/log4qt/lib/

DEPENDPATH += $$log4qt_lib
INCLUDEPATH += $$log4qt_inc

DEPENDPATH += $$lib_path
INCLUDEPATH += $$inc_path

LIBS += -L$$log4qt_lib -llog4qt_d
LIBS += -L$$lib_path -lqtnetworkng_d

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
