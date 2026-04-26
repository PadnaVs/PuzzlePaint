#include "framework.h"
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
		: QWidget(parent), m_pButOpenFile(nullptr), m_ImageManipulator(this)
	{
		ui.setupUi(this);

		m_pButOpenFile = ui.m_OpenImgBut;

		m_ImageManipulator.SetGraphicsView(ui.m_graphicsView);

		connect(m_pButOpenFile, &QPushButton::clicked, this, &QtPZPMainWindow::slotOpenFile);
		connect(this, &QtPZPMainWindow::signalOpenFile, this, &QtPZPMainWindow::slotShowImage);

		connect(ui.m_pushButton_2, &QPushButton::clicked, this, &QtPZPMainWindow::slotTest);
	}

	QtPZPMainWindow::~QtPZPMainWindow()
	{

	}

	void QtPZPMainWindow::slotOpenFile()
	{
		signalOpenFile(OpenFile());
	}
	
	void QtPZPMainWindow::slotTest()
	{
		m_ImageManipulator.Update();
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
		colorSheme.resize(image.width());
		for (int i = 0; i < image.width(); ++i)
		{
			std::vector<std::vector<int>> colorLine; 
			colorLine.resize(image.height());

			for (int j = 0; j < image.height(); ++j)
			{
				QRgb qColor = image.pixel(i, j);
				std::vector<int> color { qRed(qColor), qGreen(qColor), qBlue(qColor)};
				colorLine[j] = std::move(color);
			}

			colorSheme[i] = std::move(colorLine);
		}

	/*	QtPZPApplication* pApp = GetPZPQtApplication();
		if (!pApp)
			return;

		UIMediatorComponent* pMediator = pApp->GetUIMediator();
		if (!pMediator)
			return;*/

	/*	pMediator->LoadImage(colorSheme);*/
	}

	std::wstring QtPZPMainWindow::OpenFile()
	{
		std::wstring strRes;

		CommandOpenFile commandOpenFile(strRes);
		commandOpenFile.Run();

		return strRes;
	}
	
	void QtPZPMainWindow::DrawImage(std::vector<std::vector<std::vector<int>>>* pArrPixelMap)
	{
		if (!pArrPixelMap)
			return;
		
		unsigned int nWidth = pArrPixelMap->size();
		unsigned int nHeight = pArrPixelMap->at(0).size();

		m_ImageManipulator.CreateNewImage(nWidth, nHeight);
		m_ImageManipulator.ChangeImage(0,0, nWidth, nHeight,  pArrPixelMap);
	}

	void QtPZPMainWindow::SetCore(PzpCoreApp::IPZPCore* pCore)
	{
		m_pCore = pCore;
	}
}
