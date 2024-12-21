#include "QtPZPMainWindow.h"
#include "QtPZPApplication.h"
#include "Commands.h"
#include "QImage.h"
#include "qplugin.h"
#include <QPluginLoader>
#include <QMessageBox>

namespace PzpUI
{
	QtPZPMainWindow::QtPZPMainWindow(QWidget* parent)
		: QWidget(parent), m_pButOpenFile(nullptr)
	{
		ui.setupUi(this);

		m_pButOpenFile = ui.m_OpenImgBut;

		connect(m_pButOpenFile, &QPushButton::clicked, this, &QtPZPMainWindow::slotOpenFile);
		connect(this, &QtPZPMainWindow::signalOpenFile, this, &QtPZPMainWindow::slotShowImage);
	}

	QtPZPMainWindow::~QtPZPMainWindow()
	{

	}

	void QtPZPMainWindow::slotOpenFile()
	{
		CommandOpenFile cof(m_UICommandHabdler);
		signalOpenFile(cof.Run());
	}

	void QtPZPMainWindow::slotShowImage(std::wstring strFilename)
	{
		if(strFilename.empty())
			return;

		QString qStrFileName = QString::fromStdWString(strFilename);
		QImage image;
		if (!image.load(qStrFileName)) 
		{
			const std::wstring& strTitle = L"Ошибка!";
			const std::wstring& strText = L"Слишком большой файл. Файл не должен привышать 128 мб.";

			QMessageBox::warning(this, QString::fromStdWString(strTitle), QString::fromStdWString(strText));
		}
			

		std::vector<std::vector<std::vector<int>>> colorSheme;

		for (int i = 0; i < image.width(); ++i)
		{
			std::vector<std::vector<int>> colorLine;
			for (int j = 0; j < image.height(); ++j)
			{
				QRgb qColor = image.pixel(i, j);
				std::vector<int> color { qRed(qColor), qGreen(qColor), qBlue(qColor)};
				colorLine.push_back(color);
			}

			colorSheme.push_back(colorLine);
		}

		QtPZPApplication* pApp = GetPZPQtApplication();
		if (!pApp)
			return;

		UIMediatorComponent* pMediator = pApp->GetUIMediator();
		if (!pMediator)
			return;

		pMediator->LoadImage(colorSheme);
	}

	/*void QtPZPMainWindow::slotPushButton()
	{
		QtPZPApplication* pApp = GetPZPQtApplication();
		if (!pApp)
			return;

		pApp->GetUIMediator()->DoA();
	}*/
}
