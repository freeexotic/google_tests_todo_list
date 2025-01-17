TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    task.cpp \
    tasks_list.cpp \
    main.cpp

LIBS += -lgtest -lgtest_main -lpthread

HEADERS += \
    task.hpp \
    tasks_list.hpp
