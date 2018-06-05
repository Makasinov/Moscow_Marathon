#-------------------------------------------------
#
# Project created by QtCreator 2018-01-06T23:16:10
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled18
TEMPLATE = app

RESOURCES += res.qrc

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    more_info.cpp \
    previous_results.cpp \
    about_ms.cpp \
    interactive_map.cpp \
    wannabecomearunner.cpp \
    logindialog.cpp \
    donatesponsor.cpp \
    bmr.cpp \
    bmi.cpp \
    runnercreate.cpp \
    sponsorslist.cpp

HEADERS += \
        widget.h \
    more_info.h \
    previous_results.h \
    about_ms.h \
    interactive_map.h \
    wannabecomearunner.h \
    stylesheets.h \
    logindialog.h \
    donatesponsor.h \
    bmr.h \
    bmi.h \
    runnercreate.h \
    sponsorslist.h

FORMS += \
        widget.ui \
    more_info.ui \
    previous_results.ui \
    about_ms.ui \
    interactive_map.ui \
    wannabecomearunner.ui \
    logindialog.ui \
    donatesponsor.ui \
    bmr.ui \
    bmi.ui \
    runnercreate.ui \
    sponsorslist.ui
