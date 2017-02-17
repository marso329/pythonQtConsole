
#ifndef MAINWINDOW_
#define MAINWINDOW_
#include "ui_mainwindow.h"

class MainWindow: public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();
private:
	Ui::MainWindow* ui;
protected:

};
#endif
