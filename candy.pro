#-------------------------------------------------
#
# Project created by QtCreator 2015-06-19T10:24:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blank.cpp \
    star.cpp \
    Destroy.cpp \
    horizontal.cpp \
    vertical.cpp \
    nineblock.cpp \
    threecol.cpp \
    threerow.cpp

HEADERS  += mainwindow.h \
    blank.h \
    star.h \
    Destroy.h \
    horizontal.h \
    vertical.h \
    nineblock.h \
    threecol.h \
    threerow.h

FORMS    += mainwindow.ui

RESOURCES += \
    pic.qrc
