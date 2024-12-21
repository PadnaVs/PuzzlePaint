#pragma once

#include <QWidget>
#include "ui_QtMainWindow.h"
#include "UICommandHandler.h"

namespace PzpUI
{
	class QtPZPMainWindow : public QWidget
	{
		Q_OBJECT

	public:
		QtPZPMainWindow(QWidget* parent = nullptr);
		~QtPZPMainWindow();

	signals:
		void signalOpenFile(std::wstring strFilename);

	private slots:
		void slotOpenFile();
		void slotShowImage(std::wstring strFilename);

	private:
		Ui::QtMainWindowClass ui;

		QPushButton* m_pButOpenFile;

		UICommandHandler m_UICommandHabdler;
	};
}