#include "QtPZPApplication.h"
#include <iostream>

namespace PzpUI
{
	QtPZPApplication::QtPZPApplication(int& argc, char** argv, int flags /*= ApplicationFlags*/) : QApplication(argc, argv, flags)
	{
		connect(&m_mainWindow, SIGNAL(m_mainWindow.signalPushButton()), this, SLOT(slotPushBut()));
	}

	QtPZPApplication::~QtPZPApplication()
	{

	}

	void QtPZPApplication::ShowWindow()
	{
		m_mainWindow.show();
	}


	UIMediatorComponent* QtPZPApplication::GetUIMediator()
	{
		return &m_uiMediator;
	}


/*
	void QtPZPApplication::SetText(const std::wstring& strText)
	{
		m_mainWindow.SetText(strText);
	}*/

	void QtPZPApplication::slotPushBut()
	{
		//m_uiMediator.LoadImage();
	}
}