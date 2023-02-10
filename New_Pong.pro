TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

SOURCES += \
    Ball.cpp \
    Configuration.cpp \
    Game.cpp \
    Player.cpp \
    main.cpp


HEADERS += \
    Ball.h \
    Configuration.h \
    Game.h \
    Player.h

DISTFILES += \
    LICENSE.txt \
    README.md \
    game.config
