#pragma once

#include <QWidget>
#include "ui_QtMainWindow.h"
#include <ImageManipulator.h>
#include "..\PuzzlePaintCore\IPZPCore.h"

namespace PzpUI
{
	class QtPZPMainWindow : public QWidget
	{
		Q_OBJECT

	public:
		QtPZPMainWindow(QWidget* parent = nullptr);
		~QtPZPMainWindow();

	signals:
		void signalOpenFile(const std::wstring& strFileName);

	private slots:
		void slotOpenFile();
		void slotShowImage(const std::wstring& strFileName);

		void slotTest();

	public:
		std::wstring OpenFile();
		void DrawImage(PzpCoreApp::ImageLayer* pImage);
		
		void SetCore(PzpCoreApp::IPZPCore* pCore);
	private:
		Ui::QtMainWindowClass ui;

		QPushButton* m_pButOpenFile;

		PzpCoreApp::IPZPCore* m_pCore;

		ImageManipulator m_ImageManipulator;
	};
}