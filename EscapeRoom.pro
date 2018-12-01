#-------------------------------------------------
#
# Project created by QtCreator 2018-11-26T16:33:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EscapeRoomV01
TEMPLATE = app


SOURCES += sources/main.cpp\
        sources/mainwindow.cpp\
        sources/game.cpp\
    sources/player.cpp \
    sources/gift.cpp \
    sources/key.cpp \
    sources/door.cpp \
    sources/ingameobjects.cpp \
    sources/chest.cpp \
    sources/puzzle_1.cpp

HEADERS  += headers/mainwindow.h \
    headers/game.h \
    headers/player.h \
    headers/gift.h \
    headers/key.h \
    headers/door.h \
    headers/ingameobjects.h \
    headers/chest.hpp \
    headers/puzzle_1.h

FORMS    += ui/mainwindow.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    resources/levels/firstlevel_0_3_1_1.png
