TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Engine/src/random_numbers.cpp \
    Engine/src/skatdeck.cpp \
    Engine/src/trick.cpp \
    Engine/src/skatgameresult.cpp \
    Engine/src/skatgamesetup.cpp \
    Engine/src/iplayer.cpp

HEADERS += \
    Engine/include/card.h \
    Engine/include/ideck.h \
    Engine/include/random_numbers.h \
    Engine/include/itable.h \
    Engine/include/iplayer.h \
    Engine/include/skatdeck.h \
    Engine/include/trick.h \
    Engine/include/skatgameresult.h \
    Engine/include/skatgamesetup.h \
    Engine/include/skatplayer.h

