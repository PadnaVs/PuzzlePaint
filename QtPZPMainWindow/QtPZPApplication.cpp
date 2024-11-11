#include "QtPZPApplication.h"
#include <iostream>


QtPZPApplication::QtPZPApplication(int& argc, char** argv, int flags /*= ApplicationFlags*/) : QApplication(argc, argv, flags)
{

}

QtPZPApplication::~QtPZPApplication()
{

}

void QtPZPApplication::ShowWindow()
{
	m_mainWindow.show();
}
