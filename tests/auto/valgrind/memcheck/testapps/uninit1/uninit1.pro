TEMPLATE = app
TARGET = uninit1

CONFIG += debug console
CONFIG -= qt
win32-msvc*:QMAKE_CXXFLAGS += -w4700
else:QMAKE_CXXFLAGS = -O0 -Wno-uninitialized

macx:CONFIG -= app_bundle

SOURCES += main.cpp
