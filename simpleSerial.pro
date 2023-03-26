#-------------------------------------------------
#
# Project created by QtCreator 2018-05-23T06:33:55
#
#-------------------------------------------------

QT       += core gui serialport
QT       += core gui charts
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simpleSerial
TEMPLATE = app


SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
        mainwindow.ui

QMAKE_CXXFLAGS += -std=gnu++14
