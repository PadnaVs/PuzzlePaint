#pragma once

#include <QWidget>
#include "ui_QtMainWindow.h"

class QtPZPMainWindow : public QWidget
{
	Q_OBJECT

public:
	QtPZPMainWindow(QWidget *parent = nullptr);
	~QtPZPMainWindow();

private:
	Ui::QtMainWindowClass ui;
};
