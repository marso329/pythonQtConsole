QT += core gui widgets

TARGET = pythonQtConsole
TEMPLATE = lib

CONFIG += qt
CONFIG += no_keywords

QMAKE_CXXFLAGS += -g -std=c++11 -shared -Wl,--export-dynamic

OBJ_DIR = build
OBJECTS_DIR = build
MOC_DIR = build
DESTDIR = lib
INCLUDEDIR=include
SRCDIR=src

SOURCES +=	$$SRCDIR/pythonconsole.cpp \
		$$SRCDIR/pythonConsoleMain.cpp \
		$$SRCDIR/pythonstdioredirect.cpp \
		$$SRCDIR/history.cpp \
		$$SRCDIR/stdoutRedirect.cpp \
		$$SRCDIR/worker.cpp
			

HEADERS +=	$$INCLUDEDIR/pythonConsoleMain.h \
		$$INCLUDEDIR/pythonconsole.h \
		$$INCLUDEDIR/pythonstdioredirect.h \
		$$INCLUDEDIR/history.h \
		$$INCLUDEDIR/stdoutRedirect.h\
         	$$INCLUDEDIR/worker.h

LIBS += -L/usr/lib/python3.5/config-3.5m-x86_64-linux-gnu -lpython3.5 -L/usr/lib -lboost_python-py35	

INCLUDEPATH += /usr/include/python3.5 ./$${INCLUDEDIR}


