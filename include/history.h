#include <QTextEdit>
#include <QTextCursor>

class History:public QTextEdit{
	Q_OBJECT
public:
	History(QWidget* parent);
	~History();
public Q_SLOTS:
void insertPlainText(const QString&);
void resizeEvent(QResizeEvent * event);
};
