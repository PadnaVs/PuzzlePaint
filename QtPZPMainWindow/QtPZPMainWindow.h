﻿#pragma once

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

	signals:
		void signalOpenFile(std::wstring strFileName);

	private slots:
		void slotOpenFile();
		void slotShowImage(std::wstring strFileName);

	public:
		std::wstring OpenFile();
		void DrawImage(std::vector<std::vector<std::vector<int>>>* pArrPixelMap);

	private:
		Ui::QtMainWindowClass ui;

		QPushButton* m_pButOpenFile;
		std::unique_ptr<QGraphicsScene> m_pScene;
		QGraphicsView* m_pGraphicsView;
	};
}