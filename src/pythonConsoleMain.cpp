#include "pythonConsoleMain.h"


pythonConsoleMain::pythonConsoleMain(QWidget* parent):QWidget(parent){
	QGridLayout *layout = new QGridLayout(this);
	pc=new PythonConsole(this);
	History* qte =new History(this);
	QSplitter *splitter = new QSplitter();
	splitter->setOrientation(Qt::Vertical);
	layout->addWidget(splitter,0,0);
	splitter->addWidget(qte);
	splitter->addWidget(pc);
	splitter->setStretchFactor ( 0, 1 );
	splitter->setStretchFactor ( 1, 0 );
	    this->setLayout(layout);
	    //insertPlainText(const QString & text)
	    QObject::connect(pc, SIGNAL(sendStringToOutput(const QString&)),
	    		qte, SLOT(insertPlainText(const QString&)));

}

boost::python::dict pythonConsoleMain::getMainNamespace(){
	return pc->main_namespace;
}

void pythonConsoleMain::setMainNamespace(boost::python::dict main_namespace){
	pc->main_namespace=main_namespace;
}
pythonConsoleMain::~pythonConsoleMain(){

}
