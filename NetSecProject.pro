#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T12:12:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetSecProject
TEMPLATE = app


SOURCES += srcs/main.cpp\
        srcs/windows/main/mainwindow.cpp

HEADERS  += includes/mainwindow.h

FORMS    += srcs/windows/main/mainwindow.ui

DISTFILES += \

RESOURCES += \
    files/files.qrc
