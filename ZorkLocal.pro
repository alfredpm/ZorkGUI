TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    Parser.cpp \
    Room.cpp \
    ZorkUL.cpp \
    combination.cpp \
    enemy.cpp \
    fixedItem.cpp \
    item.cpp \
    mainwindow.cpp \
    moveableItem.cpp

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    combination.h \
    enemy.h \
    item.h \
    fixedItem.h \
    mainwindow.h \
    moveableItem.h

QT += widgets

FORMS +=
