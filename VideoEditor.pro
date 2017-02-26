#-------------------------------------------------
#
# Project created by QtCreator 2012-03-04T23:24:55
#
#-------------------------------------------------

QT += core gui widgets

TARGET = VideoEditor
TEMPLATE = app

CONFIG += qt
CONFIG += no_keywords

QMAKE_CXXFLAGS += -g -std=c++11 -shared -Wl,--export-dynamic

DEFINES +=

OBJ_DIR = debug
OBJECTS_DIR = debug
MOC_DIR = debug

SOURCES += ./main.cpp \
		./pythonconsole.cpp \
		./pythonConsoleMain.cpp \
	mainwindow.cpp \
	./pythonstdioredirect.cpp \
	./history.cpp \
	./stdoutRedirect.cpp \
	./worker.cpp
			

HEADERS += ./mainwindow.h \
./pythonConsoleMain.h \
		./pythonconsole.h \
		./pythonstdioredirect.h \
		./history.h \
		./stdoutRedirect.h\
         ./worker.h
LIBS += -L/usr/lib/python3.5/config-3.5m-x86_64-linux-gnu -lpython3.5 -L/usr/lib -lboost_python-py35	

INCLUDEPATH += /usr/include/python3.5

FORMS    += ./mainwindow.ui


