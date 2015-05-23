#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T12:08:54
#
#-------------------------------------------------

QT       += core gui

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
    background.cpp

HEADERS  += mainwindow.h \
    gamewindow.h \
    tank.h \
    bottank.h \
    bullet.h \
    playertank.h \
    background.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11

RESOURCES     = img_resource.qrc




#RESOURCES += img/*.png\
#             img/*.jpeg\
#             img/*.jpg\
