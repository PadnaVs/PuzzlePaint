#pragma once
#include "Header.h"
#include "ui_QTMainWindow.h"

class QTMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QTMainWindow(QWidget *parent = nullptr);
	~QTMainWindow();

private:
	Ui::QTMainWindowClass ui;
};
