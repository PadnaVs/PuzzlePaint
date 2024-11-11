#pragma once
#include <QApplication>
#include <QWidget>
#include "DI.h"
#include "qtpzpmainwindow_global.h"
#include "QtPZPMainWindow.h"

class QtPZPApplication :
	public QApplication
{
	template<class I, class T>
	friend class DI;
public:
	QtPZPApplication(int& argc, char** argv, int flags = ApplicationFlags);;
	virtual ~QtPZPApplication();

	void ShowWindow();
private:
	QtPZPMainWindow m_mainWindow;
};


