#include "pythonconsole.h"

PythonConsole::PythonConsole(QWidget* parent) :
		QTextEdit(parent) {
	QFont font;
	font.setFamily("Courier");
	font.setStyleHint(QFont::Monospace);
	font.setFixedPitch(true);
	font.setPointSize(10);
	setFont(font);
	QFontMetrics metrics(font);
	setTabStopWidth(4 * metrics.width(' '));
	historyPosition = 0;
	mode = normal;
    _completer = new QCompleter(this);
    _completer->setWidget(this);
    std::string tempName="VideoEditor";
    try {
      Py_Initialize();
      main_module = import("__main__");
      main_namespace = extract<dict>(main_module.attr("__dict__"));
      dict builtins=extract<dict>(main_namespace["__builtins__"].attr("__dict__"));
      list keys = builtins.keys();
      for (std::size_t i=0;i<len(keys);i++){
    	  std::cout<<keys[i];

      }
      //for (auto it=builtins.begin();it!=builtins.end();it++){

      //}
      //dict globals =extract<dict>(builtins["globals"]());

      handle<> ignored(( PyRun_String( "globals()",
                                       Py_file_input,
                                       main_namespace.ptr(),
                                       main_namespace.ptr() ) ));
    } catch( error_already_set ) {
      PyErr_Print();
    }
}

void PythonConsole::advanceHistory() {
	historyPosition++;
	if (historyPosition > history.size()) {
		historyPosition = history.size();
	}

}

void PythonConsole::retardHistory() {
	if (historyPosition == 0) {
		return;
	}
	historyPosition--;
	if (historyPosition == 0 && history.size() != 0) {
		historyPosition = 1;
	}
}

const std::string& PythonConsole::getCurrentHistory() {
	static const std::string empty = "";
	if (historyPosition == 0) {
		return empty;
	} else {
		return history[historyPosition - 1];
	}
}

void PythonConsole::addLineToHistory(const std::string& newLine) {
	history.push_back(newLine);
	historyPosition = history.size();
}
void PythonConsole::keyPressEvent(QKeyEvent *e) {
	std::vector<std::string> lines;
	std::vector<std::string> wordsOnCurrentLine;
	std::string textInEditor = toPlainText().toStdString();
	//split text into lines
	boost::split(lines, textInEditor, boost::is_any_of("\n"),
			boost::token_compress_on);
	//count number of tabs on current row
	//unsigned tabs = std::count(lines.back().begin(), lines.back().end(), '\t');
	char lastChar = toPlainText().toStdString()[toPlainText().length() - 1];
	std::string lastLine = lines.back();

//	unsigned tabs = std::count(lastline.begin(), lastline.end(), '\t');
	unsigned tabs=0;
	for (auto it =lastLine.begin();it!=lastLine.end();it++){
		if (*it=='\t'){
			tabs++;
		}
		else{
			break;
		}
	}
	int currentLine = textCursor().blockNumber() + 1;
	//event to insert tabs the correct way
	QKeyEvent* tabsEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab,
			Qt::NoModifier, "\t");
	switch (mode) {
	case normal: {
		switch (e->key()) {
		//normal mode enter
		case Qt::Key_Return: {
			history.push_back(lastLine);
			//if last was an if or for... statement
			if (lastChar == ':') {
				QTextEdit::keyPressEvent(e);
				for (std::size_t i = 0; i < tabs + 1; i++) {
					keyPressEvent(tabsEvent);
				}
				delete tabsEvent;
				return;
			} else {
				QTextEdit::keyPressEvent(e);
				for (std::size_t i = 0; i < tabs; i++) {
					keyPressEvent(tabsEvent);
				}
				delete tabsEvent;
				return;
			}
		}
		case Qt::Key_Up: {
			addLineToHistory(lastLine);
			retardHistory();
			QTextCursor cursor = textCursor();
			cursor.movePosition(QTextCursor::Start);
			cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor,
					currentLine);
			cursor.select(QTextCursor::LineUnderCursor);
			cursor.removeSelectedText();
			cursor.insertText(QString::fromStdString(getCurrentHistory()));
			cursor.movePosition(QTextCursor::End);
			setTextCursor(cursor);
			mode = historyMode;
			return;
		}
		}
		break;
	}
	case historyMode: {
		switch (e->key()) {
		case Qt::Key_Up: {
			retardHistory();
			QTextCursor cursor = textCursor();
			cursor.movePosition(QTextCursor::Start);
			cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor,
					currentLine);
			cursor.select(QTextCursor::LineUnderCursor);
			cursor.removeSelectedText();
			cursor.insertText(QString::fromStdString(getCurrentHistory()));
			cursor.movePosition(QTextCursor::End);
			setTextCursor(cursor);
			return;
		}
		case Qt::Key_Down: {
			advanceHistory();
			QTextCursor cursor = textCursor();
			cursor.movePosition(QTextCursor::Start);
			cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor,
					currentLine);
			cursor.select(QTextCursor::LineUnderCursor);
			cursor.removeSelectedText();
			cursor.insertText(QString::fromStdString(getCurrentHistory()));
			cursor.movePosition(QTextCursor::End);
			setTextCursor(cursor);
			return;
		}
		default: {
			mode = normal;
			break;
		}
		}

		break;
	}
	default: {

	}
	}
	QTextEdit::keyPressEvent(e);
}

PythonConsole::~PythonConsole() {
}
