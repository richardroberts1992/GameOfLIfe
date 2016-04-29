#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T15:17:21
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOfLife
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lifewindow.cpp \
    lifegrid.cpp \
    lifenode.cpp

HEADERS  += mainwindow.h \
    lifewindow.h \
    lifegrid.h \
    lifenode.h

FORMS    += mainwindow.ui
