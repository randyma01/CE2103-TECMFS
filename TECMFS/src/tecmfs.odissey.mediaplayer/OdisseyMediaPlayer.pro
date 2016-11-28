#-------------------------------------------------
#
# Project created by QtCreator 2016-11-19T23:12:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OdisseyMediaPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    converter.cpp \
    encripter.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    converter.h \
    encripter.h \
    player.h

FORMS    += \
    ../../workspace/TECMFS-OdisseyMP/odisseyMP.ui


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libzip
unix: PKGCONFIG += zlib
unix: PKGCONFIG += opencv
unix: PKGCONFIG += libmediainfo

RESOURCES += \
    images.qrc


