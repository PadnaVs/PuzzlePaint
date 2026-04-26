#include "QtPZPApplication.h"
#include "Start.h"
#include <iostream>

namespace PzpUI
{
	QtPZPApplication::QtPZPApplication(int& argc, char** argv, int flags /*= ApplicationFlags*/) 
		: QApplication(argc, argv, flags), m_mainWindow(std::make_unique<QtPZPMainWindow>())
	{
		m_mainWindow->SetCore(GetCore());
		//connect(&m_mainWindow, SIGNAL(m_mainWindow.signalPushButton()), this, SLOT(slotPushBut()));
	}

	QtPZPApplication::~QtPZPApplication()
	{

	}

	void QtPZPApplication::ShowWindow()
	{
		m_mainWindow->show();
	}

	void QtPZPApplication::slotPushBut()
	{
		
	}
}