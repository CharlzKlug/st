#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T17:14:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = curvesCombo
TEMPLATE = app

SOURCES += main.cpp\
        mainwin.cpp \
    function.cpp \
    myPainter.cpp \    
    filefunc.cpp

HEADERS  += mainwin.h \
    function.h \
    myPainter.h \
    filefunc.h

RESOURCES += \
    filestr.qrc
