QT += core
QT -= gui

CONFIG += c++11

TARGET = QThreadPractice3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    worker.cpp \
    controller.cpp

HEADERS += \
    controller.h \
    worker.h
