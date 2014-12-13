TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/SDL2
LIBS += -lSDL2
LIBS += -lSDL2_ttf
LIBS += -lSDL2_image


SOURCES += main.cpp \
    Ant.cpp \
    Case.cpp \
    Grille.cpp \
    Miel.cpp \
    Colony.cpp \
    Wall.cpp \
    Direction.cpp \
    functions.cpp \
    Settings.cpp \
    Bouton.cpp

HEADERS += \
    Ant.h \
    Case.h \
    Grille.h \
    Miel.h \
    Colony.h \
    Wall.h \
    Direction.h \
    functions.h \
    Settings.h \
    Bouton.h

