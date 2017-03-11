#include "history.h"

History::History(QWidget* parent):QTextEdit(parent){
	QFont font;
	font.setFamily("Courier");
	font.setStyleHint(QFont::Monospace);
	font.setFixedPitch(true);
	font.setPointSize(10);
	setFont(font);
	QFontMetrics metrics(font);
	setTabStopWidth(4 * metrics.width(' '));
	setReadOnly(true);
}

History::~History(){

}

 void History::resizeEvent(QResizeEvent * event){
	 QTextEdit::resizeEvent(event);
		QTextCursor c = textCursor();
		c.movePosition(QTextCursor::End);
		setTextCursor(c);

}
void History::insertPlainText(const QString& data){
	QTextEdit::insertPlainText(data);
	QTextCursor c = textCursor();
	c.movePosition(QTextCursor::End);
	setTextCursor(c);
}
