#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T12:08:54
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FenixTanks
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp \
           gamewindow.cpp \
           tank.cpp \
           bottank.cpp \
           bullet.cpp \
           playertank.cpp \
           background.cpp \
           button.cpp \
           brick.cpp \
           map.cpp \
           solidbrick.cpp \
           fenix.cpp \
    specialqgraphicspixmapitem.cpp \
    explosion.cpp

HEADERS  += mainwindow.h \
            gamewindow.h \
            tank.h \
            bottank.h \
            bullet.h \
            playertank.h \
            background.h \
            button.h \
            brick.h \
            solidbrick.h \
            map.h \
            fenix.h \
    specialqgraphicspixmapitem.h \
    explosion.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11

RESOURCES     += res.qrc
