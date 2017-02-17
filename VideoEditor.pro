#-------------------------------------------------
#
# Project created by QtCreator 2012-03-04T23:24:55
#
#-------------------------------------------------

QT += core gui widgets

TARGET = VideoEditor
TEMPLATE = app

CONFIG += qt

QMAKE_CXXFLAGS += -g -std=c++11

DEFINES +=

OBJ_DIR = debug
OBJECTS_DIR = debug
MOC_DIR = debug

SOURCES += ./main.cpp \
		./pythonconsole.cpp \
	mainwindow.cpp
			

HEADERS += ./mainwindow.h \
		./pythonconsole.h
         
LIBS +=

INCLUDEPATH +=

FORMS    += ./mainwindow.ui


