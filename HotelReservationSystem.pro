TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        guest.cpp \
        hotel.cpp \
        humanguest.cpp \
        humanroom.cpp \
        main.cpp \
        monsterguest.cpp \
        monsterroom.cpp \
        receptionist.cpp \
        room.cpp \
        user.cpp

HEADERS += \
    guest.h \
    hotel.h \
    humanguest.h \
    humanroom.h \
    monsterguest.h \
    monsterroom.h \
    receptionist.h \
    room.h \
    user.h
