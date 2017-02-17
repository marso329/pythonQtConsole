#ifndef PYTHONCONSOLE_H
#define PYTHONCONSOLE_H
#include <QTextEdit>
#include <QKeyEvent>
 #include <QDebug> 
#include <QCompleter>
#include <iostream>
#include <algorithm>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <vector>

enum EditorMode { normal,historyMode };

class PythonConsole:public QTextEdit{
Q_OBJECT
public:
PythonConsole(QWidget* parent);
~PythonConsole();
private:
const std::string& getCurrentHistory();
void advanceHistory();
void retardHistory();
void addLineToHistory(const std::string& newLine);
EditorMode mode= normal;
std::vector<std::string> history;
std::size_t historyPosition;
QCompleter* _completer;
public Q_SLOTS:
void keyPressEvent(QKeyEvent *e);
};

#endif
