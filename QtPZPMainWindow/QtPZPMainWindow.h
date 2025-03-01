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

	public:
		void DrawImage(std::vector<std::vector<std::vector<int>>>* pArrPixelMap);

	private:
		Ui::QtMainWindowClass ui;

		QPushButton* m_pButOpenFile;
		std::unique_ptr<QGraphicsScene> m_pScene;
		QGraphicsView* m_pGraphicsView;

		UICommandHandler m_UICommandHabdler;
	};
}