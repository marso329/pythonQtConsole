#ifndef STDOUTREDIRECT
#define STDOUTREDIRECT
#include <QObject>
#include <QString>
#include <iostream>

class stdoutRedirection:public QObject{
	Q_OBJECT
public:
	stdoutRedirection(QObject* parent);
	~stdoutRedirection();
	void write(std::string  str );
Q_SIGNALS:
void gotOutput(const QString& data);
};
#endif
