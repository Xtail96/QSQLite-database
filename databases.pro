#-------------------------------------------------
#
# Project created by QtCreator 2017-12-21T21:51:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = databases
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        gui/mainwindow.cpp \
    models/sqliteadapter.cpp \
    controllers/mainwindowcontroller.cpp \
    gui/addworkerdialog.cpp \
    gui/deleteworkerdialog.cpp \
    gui/addbreeddialog.cpp

HEADERS += \
        gui/mainwindow.h \
    models/sqliteadapter.h \
    controllers/mainwindowcontroller.h \
    gui/addworkerdialog.h \
    gui/deleteworkerdialog.h \
    gui/addbreeddialog.h

FORMS += \
        gui/mainwindow.ui \
    gui/addworkerdialog.ui \
    gui/deleteworkerdialog.ui \
    gui/addbreeddialog.ui
