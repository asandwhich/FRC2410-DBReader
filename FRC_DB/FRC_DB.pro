#-------------------------------------------------
#
# Project created by QtCreator 2013-02-15T19:41:31
#
#-------------------------------------------------

QT       += core gui

QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FRC_DB
TEMPLATE = app

CONFIG += static

SOURCES += main.cpp\
        mainwindow.cpp \
    databasemanager.cpp

HEADERS  += mainwindow.h \
    databasemanager.h

FORMS    += mainwindow.ui

RESOURCES +=

QMAKE_CXXFLAGS += -std=gnu++0x
