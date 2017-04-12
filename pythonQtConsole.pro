include ( common.prf ) 

QT += core gui widgets

TARGET = pythonQtConsole
TEMPLATE = lib

CONFIG += qt
CONFIG += no_keywords

QMAKE_CXXFLAGS += -g -std=c++11 -shared -Wl,--export-dynamic -pedantic -Werror -Wall

OBJ_DIR = build
OBJECTS_DIR = build
MOC_DIR = build
DESTDIR = lib
INCLUDEDIR=include
SRCDIR=src

SOURCES +=	$$SRCDIR/pythonconsole.cpp \
		$$SRCDIR/pythonConsoleMain.cpp \
		$$SRCDIR/history.cpp \
		$$SRCDIR/stdoutRedirect.cpp \
		$$SRCDIR/worker.cpp
			

HEADERS +=	$$INCLUDEDIR/pythonConsoleMain.h \
		$$INCLUDEDIR/pythonconsole.h \
		$$INCLUDEDIR/history.h \
		$$INCLUDEDIR/stdoutRedirect.h\
         	$$INCLUDEDIR/worker.h

INCLUDEPATH +=./$${INCLUDEDIR}


