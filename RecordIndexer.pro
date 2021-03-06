#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T00:39:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RecordIndexer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bplus.c \
    addrecord.cpp \
    deleterecord.cpp \
    listpage.cpp \
    querybrowser.cpp

HEADERS  += mainwindow.h \
    bplus.h \
    sum.h \
    addrecord.h \
    deleterecord.h \
    listpage.h \
    querybrowser.h

FORMS    += mainwindow.ui \
    addrecord.ui \
    deleterecord.ui \
    listpage.ui \
    querybrowser.ui
