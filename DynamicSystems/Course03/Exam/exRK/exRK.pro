QT += core
QT -= gui

CONFIG += c++11

TARGET = exRK
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    vector.cpp \
    rkmethod.cpp

HEADERS += \
    vector.h \
    rkmethod.h
