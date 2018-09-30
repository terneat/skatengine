#-------------------------------------------------
#
# Project created by QtCreator 2017-10-15T09:55:29
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SkatQTandEngine
TEMPLATE = app


SOURCES += main.cpp\
        qskatmainwindow.cpp \
    interface/qskatengine.cpp \
    skatEngine/src/card.cpp \
    skatEngine/src/cardset.cpp \
    skatEngine/src/cpuplayer.cpp \
    skatEngine/src/game.cpp \
    skatEngine/src/humanplayer.cpp \
    skatEngine/src/player.cpp \
    skatEngine/src/random_numbers.cpp \
    skatEngine/skatengine.cpp \
    skatEngine/src/round.cpp \
    ui/skatgamewindow.cpp \
    ui/showcardsscene.cpp \
    ui/carditem.cpp \
    skatEngine/src/decisionmaker.cpp \
    skatEngine/src/trick.cpp \
    skatEngine/src/roundinfo.cpp

HEADERS  += qskatmainwindow.h \
    interface/qskatengine.h \
    skatEngine/include/card.h \
    skatEngine/include/cardset.h \
    skatEngine/include/cpuplayer.h \
    skatEngine/include/game.h \
    skatEngine/include/humanplayer.h \
    skatEngine/include/player.h \
    skatEngine/include/random_numbers.h \
    skatEngine/skatengine.h \
    skatEngine/skatenums.h \
    skatEngine/include/round.h \
    ui/skatgamewindow.h \
    ui/showcardsscene.h \
    ui/carditem.h \
    skatEngine/include/decisionmaker.h \
    skatEngine/include/trick.h \
    skatEngine/include/roundinfo.h

FORMS    += qskatmainwindow.ui \
    ui/skatgamewindow.ui

RESOURCES += \
    pics.qrc
