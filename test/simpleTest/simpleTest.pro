include ( ../../common.prf ) 

QT += core gui widgets

TARGET = simpleTest
TEMPLATE = app

CONFIG += qt
CONFIG += no_keywords

SOURCES += ./main.cpp \
	mainwindow.cpp \
			
DEPENDPATH += . ../../include
INCLUDEPATH += ../../include


HEADERS += ./mainwindow.h 

LIBS += -L../../lib -lpythonQtConsole


FORMS    += ./mainwindow.ui

