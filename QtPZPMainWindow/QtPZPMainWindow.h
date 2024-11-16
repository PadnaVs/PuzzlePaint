#pragma once

#include <QWidget>
#include "ui_QtMainWindow.h"

namespace PzpUI
{
	class QtPZPMainWindow : public QWidget
	{
		Q_OBJECT

	public:
		QtPZPMainWindow(QWidget* parent = nullptr);
		~QtPZPMainWindow();


		void SetText(const std::wstring& strText);

	signals:
		void signalPushButton();

	private slots:
		void slotPushButton();

	private:
		Ui::QtMainWindowClass ui;
	};
}