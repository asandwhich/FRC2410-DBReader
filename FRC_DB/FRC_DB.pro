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



SOURCES += main.cpp\
        mainwindow.cpp \
    databasemanager.cpp \
    teamwindow.cpp

HEADERS  += mainwindow.h \
    databasemanager.h \
    teamwindow.h

FORMS    += mainwindow.ui \
    teamwindow.ui

RESOURCES +=

QMAKE_CXXFLAGS += -std=gnu++0x

CONFIG += static
static {
    CONFIG += static
    QTPLUGIN += qsqlite qsqlodbc
    DEFINES += STATIC
}
