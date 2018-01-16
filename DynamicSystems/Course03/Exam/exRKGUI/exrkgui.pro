#-------------------------------------------------
#
# Project created by QtCreator 2016-11-27T10:25:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exrkgui
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    Autopilot.cpp \
    rkmethod.cpp \
    vector.cpp

HEADERS  += widget.h \
    Autopilot.h \
    Sleeper.h \
    rkmethod.h \
    vector.h
