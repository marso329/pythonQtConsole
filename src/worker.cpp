#include "worker.h"

    void Worker::doWork(const QString & codeToExecute,boost::python::dict main_namespace) {
	bool success=false;
    	try{
    	boost::python::object tempOb = boost::python::eval(boost::python::str(codeToExecute.toStdString()),
				main_namespace, main_namespace);
    	std::string temp=boost::python::extract<std::string>(boost::python::str(tempOb))();
    	success=true;
    	if (temp!="None"){
		 Q_EMIT resultReady(QString::fromStdString(temp));
		 return;
	}
	} catch (boost::python::error_already_set ) {
	//	PyErr_Print();
		PyErr_Clear();
	}
	if (success){
		return;
	}
	try{
    	boost::python::object tempOb = boost::python::exec(boost::python::str(codeToExecute.toStdString()),
				main_namespace, main_namespace);
	} catch (boost::python::error_already_set ) {
		PyErr_Print();
		PyErr_Clear();
	}

    }
