#-------------------------------------------------
#
# Project created by QtCreator 2017-12-15T14:14:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Homework3
TEMPLATE = app
CONFIG += console c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    csppoint.cpp \
    cspobject.cpp \
    csplayer.cpp \
    cspproperty.cpp \
    cspcolor.cpp \
    cspdatabase.cpp \
    cspindex.cpp \
    cspcities.cpp \
    cspfile.cpp \
    cspmap.cpp \
    cspe00.cpp \
    csproute.cpp \
    routesearchingwindow.cpp \
    guidewindow.cpp \
    knldstywindow.cpp \
    cspshp.cpp \
    cspkernel.cpp \
    cspfield.cpp \
    cspanlztools.cpp \
    cspra.cpp \
    rawindow.cpp

HEADERS  += mainwindow.h \
    csppoint.h \
    cspobject.h \
    csplayer.h \
    cspproperty.h \
    cspcolor.h \
    cspdatabase.h \
    cspindex.h \
    cspcities.h \
    cspfile.h \
    cspmap.h \
    cspe00.h \
    csproute.h \
    routesearchingwindow.h \
    guidewindow.h \
    knldstywindow.h \
    cspshp.h \
    cspkernel.h \
    cspfield.h \
    cspanlztools.h \
    cspra.h \
    rawindow.h

FORMS    += mainwindow.ui \
    routesearchingwindow.ui \
    guidewindow.ui \
    knldstywindow.ui \
    rawindow.ui

unix|win32: LIBS += -L$$PWD/../warmerda/warmerda/lib/ -lgdal_i

INCLUDEPATH += $$PWD/../warmerda/warmerda/include
DEPENDPATH += $$PWD/../warmerda/warmerda/include
