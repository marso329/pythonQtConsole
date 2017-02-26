#include <QObject>
#include <QThread>
#include <boost/python.hpp>
class Worker : public QObject
{
    Q_OBJECT
    QThread workerThread;

public Q_SLOTS:
    void doWork(const QString &,boost::python::dict);
Q_SIGNALS:
    void resultReady(const QString &result);
};
