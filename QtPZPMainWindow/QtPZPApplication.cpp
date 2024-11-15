#include "QtPZPApplication.h"
#include <iostream>


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


void QtPZPApplication::slotPushBut()
{
	m_uiMediator.DoA();
}
