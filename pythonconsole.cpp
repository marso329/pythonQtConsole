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
	std::string tempName = "VideoEditor";
	try {
		Py_Initialize();
		main_module = import("__main__");
		main_namespace = extract<dict>(main_module.attr("__dict__"));
		dict builtins = extract<dict>(
				main_namespace["__builtins__"].attr("__dict__"));
		list keys = builtins.keys();
		for (std::size_t i = 0; i < len(keys); i++) {
			std::string value = boost::python::extract<std::string>(keys[i]);
			builtinsList.append(QString::fromStdString(value));

		}
		object keywords = import("keyword");
		boost::python::dict keyword_namespace = extract<dict>(
				keywords.attr("__dict__"));
		keys = keyword_namespace.keys();
		for (std::size_t i = 0; i < len(keys); i++) {
			std::string value = boost::python::extract<std::string>(keys[i]);
			keywordList.append(QString::fromStdString(value));

		}

		handle<> ignored(
				(PyRun_String("globals()", Py_file_input, main_namespace.ptr(),
						main_namespace.ptr())));
	} catch (error_already_set ) {
		PyErr_Print();
	}
QObject::connect(_completer, SIGNAL(activated(const QString&)),
		this, SLOT(insertCompletion(const QString&)));
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

void PythonConsole::insertCompletion(const QString& completion) {
std::cout << "activated wtih:" << std::endl;
qDebug() << completion;
QTextCursor tc = textCursor();
tc.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);
if (tc.selectedText() == ".") {
	tc.insertText(QString(".") + completion);
} else {
	tc = textCursor();
	tc.movePosition(QTextCursor::StartOfWord, QTextCursor::MoveAnchor);
	tc.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
	tc.insertText(completion);
	setTextCursor(tc);
}
}

void PythonConsole::keyPressEvent(QKeyEvent *e) {
std::vector<std::string> lines;
std::vector<std::string> wordsOnCurrentLine;
std::string textInEditor = toPlainText().toStdString();
//split text into lines
boost::split(lines, textInEditor, boost::is_any_of("\n"),
		boost::token_compress_on);
char lastChar = textInEditor[textInEditor.length() - 1];
std::string lastLine = lines.back();
boost::split(wordsOnCurrentLine, lastLine, boost::is_any_of(" \t"),
		boost::token_compress_on);
std::string lastWord = wordsOnCurrentLine.back();
unsigned tabs = 0;
for (auto it = lastLine.begin(); it != lastLine.end(); it++) {
	if (*it == '\t') {
		tabs++;
	} else {
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
	case Qt::Key_Space: {
		std::cout << "space event" << std::endl;
		//ctrl+space
		if (e->modifiers() & Qt::ControlModifier) {
			std::cout << "ctrl=space: " << lastWord << std::endl;
			QStringList found;
			QString lastWordQString = QString::fromStdString(lastWord);
			if (lastWord.size() == 0) {
				_completer->popup()->hide();
				return;
			}
			Q_FOREACH (QString n, builtinsList) {
				if (n.toLower().startsWith(lastWordQString)) {
					found << n;
				}
			}
			Q_FOREACH (QString n, keywordList) {
				if (n.toLower().startsWith(lastWordQString)) {
					found << n;
				}
			}
			if (found.size() == 0) {
				_completer->popup()->hide();
				return;
			}
			_completer->setCompletionPrefix(QString::fromStdString(lastWord));
			_completer->setCompletionMode(QCompleter::PopupCompletion);
			_completer->setModel(new QStringListModel(found, _completer));
			_completer->setCaseSensitivity(Qt::CaseInsensitive);
			QTextCursor c = textCursor();
			c.movePosition(QTextCursor::StartOfWord);
			QRect cr = cursorRect(c);
			cr.setWidth(
					_completer->popup()->sizeHintForColumn(0)
							+ _completer->popup()->verticalScrollBar()->sizeHint().width());
			cr.translate(0, 8);
			_completer->complete(cr);
			mode = completionMode;
			return;
		}

		break;
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
case completionMode: {
	std::cout << "completionmodecase" << std::endl;
	mode = normal;
	if (e->key() == Qt::Key_Return) {
		std::cout<<"enter in compeltion mode"<<std::endl;
		if (_completer->popup()->currentIndex().isValid()) {
			insertCompletion(_completer->currentCompletion());
			_completer->popup()->hide();
			e->accept();
			return;
		}
	}
	QTextEdit::keyPressEvent(e);
	QKeyEvent* completetionEvent = new QKeyEvent(QEvent::KeyPress,
			Qt::Key_Space, Qt::ControlModifier, " ");
	std::cout << "after" << std::endl;
	keyPressEvent(completetionEvent);
	std::cout << "after ev	" << std::endl;
	delete completetionEvent;
	return;
	break;
}
default: {

}
}
QTextEdit::keyPressEvent(e);
}

PythonConsole::~PythonConsole() {
}
