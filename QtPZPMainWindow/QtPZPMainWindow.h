#pragma once

#include <QWidget>
#include "ui_QtMainWindow.h"

class QtPZPMainWindow : public QWidget
{
	Q_OBJECT

public:
	QtPZPMainWindow(QWidget *parent = nullptr);
	~QtPZPMainWindow();

signals:
	void signalPushButton();

private slots:
	void slotPushButton();

private:
	Ui::QtMainWindowClass ui;
};
