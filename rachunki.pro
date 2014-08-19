#-------------------------------------------------
#
# Project created by QtCreator 2014-07-24T18:59:43
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nienazwany
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rekord.cpp \
    pugixml.cpp

HEADERS  += mainwindow.h \
    rekord.h \
    pugiconfig.hpp \
    pugixml.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
