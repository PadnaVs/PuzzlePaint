#pragma once
#include "framework.h"
#include <QApplication>
#include <QWidget>
#include "QtPZPMainWindow.h"

namespace PzpUI
{
	class QtPZPApplication :
		public QApplication
	{
		template<class I, class T>
		friend class DI;
	public:
		QtPZPApplication(int& argc, char** argv, int flags = ApplicationFlags);
		virtual ~QtPZPApplication();

		void ShowWindow();

	private slots:
		void slotPushBut();

	private:
		std::unique_ptr<QtPZPMainWindow> m_mainWindow;
	};
}


