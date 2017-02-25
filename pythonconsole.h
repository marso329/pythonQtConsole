#ifndef PYTHONCONSOLE_H
#define PYTHONCONSOLE_H
#include <QTextEdit>
#include <QKeyEvent>
 #include <QDebug> 
#include <QCompleter>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QScrollBar>
#include <iostream>
#include <QString>
#include <algorithm>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <vector>
#include <boost/python.hpp>
#include <boost/algorithm/string.hpp>

#include "pythonstdioredirect.h"

enum EditorMode { normal,historyMode,completionMode,newLine };

using namespace boost::python;

class PythonConsole:public QTextEdit{
Q_OBJECT
public:
PythonConsole(QWidget* parent);
~PythonConsole();
private:
QStringList builtinsList;
long long unsigned firstLineNumber;
QStringList keywordList;
const std::string& getCurrentHistory();
void advanceHistory();
void retardHistory();
void addLineToHistory(const std::string& newLine);
std::string executeCommand(std::string&);
EditorMode mode= normal;
std::vector<std::string> history;
std::size_t historyPosition;
boost::python::object main_module;
boost::python::dict main_namespace ;

QCompleter* _completer;
boost::python::object pythonMainModule;
PythonStdIoRedirect python_stdio_redirector;
public Q_SLOTS:
void keyPressEvent(QKeyEvent *e);
void insertCompletion(const QString&);
};

#endif
