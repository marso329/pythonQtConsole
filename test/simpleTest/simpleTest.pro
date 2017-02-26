#-------------------------------------------------
#
# Project created by QtCreator 2012-03-04T23:24:55
#
#-------------------------------------------------

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
LIBS += -L/usr/lib/python3.5/config-3.5m-x86_64-linux-gnu -lpython3.5 -L/usr/lib -lboost_python-py35	

INCLUDEPATH += /usr/include/python3.5 

