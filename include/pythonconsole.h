#ifndef PYTHONCONSOLE_H
#define PYTHONCONSOLE_H
#include <QObject>
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
#include <boost/python/module.hpp>
#include "stdoutRedirect.h"
#include <boost/smart_ptr.hpp>
#include "worker.h"
#include <QThread>

Q_DECLARE_METATYPE(boost::python::dict)
Q_DECLARE_METATYPE(std::string)
typedef boost::shared_ptr< stdoutRedirection > stdoutput_ptr;


enum EditorMode {
	normal, historyMode, completionMode, newLine
};


using namespace boost::python;

class PythonConsole: public QTextEdit {
	Q_OBJECT
public:
	PythonConsole(QWidget* parent);
	~PythonConsole();
	boost::python::object main_module;
	boost::python::dict main_namespace;
private:
	QStringList builtinsList;
	long long unsigned firstLineNumber;
	QStringList keywordList;
	const std::string& getCurrentHistory();
	void advanceHistory();
	void retardHistory();
	void removeLastLineFromHistory();
	void addLineToHistory(const std::string& newLine);
	void executeCommand(std::string&);
	EditorMode mode = normal;
	std::vector<std::string> history;
	std::size_t historyPosition;


	QCompleter* _completer;
	boost::python::object pythonMainModule;
	Worker *worker;
	QThread* workerThread;
Q_SIGNALS:
		void sendStringToOutput(const QString& data);
		void executeCode(const QString &result,boost::python::dict);


public Q_SLOTS:
	void keyPressEvent(QKeyEvent *e);
	void insertCompletion(const QString&);
	void receiveOutput(const QString&);
	void resizeEvent(QResizeEvent * event);
	void getResult(const QString&);

};

#endif
