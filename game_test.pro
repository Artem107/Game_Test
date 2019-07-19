TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        engine.cpp \
        main.cpp \
        object2d.cpp

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -pthread

HEADERS += \
    engine.h \
    object2d.h
