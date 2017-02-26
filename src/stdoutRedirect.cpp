#include "stdoutRedirect.h"

stdoutRedirection::stdoutRedirection(QObject* parent):QObject(parent){

}

stdoutRedirection::~stdoutRedirection(){

}
void stdoutRedirection::write(std::string str ){
Q_EMIT gotOutput(QString::fromStdString(str));
}
