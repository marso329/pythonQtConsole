#include "pythonconsole.h"
#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include "history.h"
#include <QSplitter>
class pythonConsoleMain:public QWidget{
	Q_OBJECT
public:
	pythonConsoleMain(QWidget* parent);
	~pythonConsoleMain();
	PythonConsole* pc;
	boost::python::dict getMainNamespace();
	void setMainNamespace(boost::python::dict);
private:
protected:


};
