#include "framework.h"
#include "QtPZPMainWindow.h"
#include "QtPZPApplication.h"
#include "Commands.h"
#include "QImage.h"
#include "qplugin.h"
#include <QPluginLoader>
#include <QMessageBox>
#include "..\PuzzlePaintCore\ImageLayer.h"

namespace PzpUI
{
	QtPZPMainWindow::QtPZPMainWindow(QWidget* parent)
		: QWidget(parent), m_pButOpenFile(nullptr), m_ImageManipulator(this), m_pCore(nullptr)
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

	void QtPZPMainWindow::slotShowImage(const std::wstring& strFilename)
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
		
		PzpCoreApp::ImageInHeap pColorSheme = std::make_unique<std::vector<std::vector<PzpCoreApp::Pixel>>>();

		size_t nWidth = image.width();
		size_t nHeight = image.height();

		pColorSheme.get()->resize(nWidth);
		for (int i = 0; i < nWidth; ++i)
		{
			std::vector<PzpCoreApp::Pixel> pixelLine;
			pixelLine.resize(nHeight);

			for (int j = 0; j < nHeight; ++j)
			{
				QRgb qColor = image.pixel(i, j);
				PzpCoreApp::Pixel pixel;
				pixel.m_nR = qRed(qColor);
				pixel.m_nG = qGreen(qColor);
				pixel.m_nB = qBlue(qColor);

				pixelLine[j] = pixel;
			};

			try 
			{
				pColorSheme->at(i) = std::move(pixelLine);
			}
			catch (const std::exception&) {	}
		}

		std::unique_ptr<PzpCoreApp::ImageLayer> pMainImg = std::make_unique<PzpCoreApp::ImageLayer>();
		pMainImg->SetPixelMap(std::move(pColorSheme));
		pMainImg->SetWidth(nWidth);
		pMainImg->SetHeight(nHeight);

		PzpCoreApp::ImageLayer* pImg = m_pCore->LoadLayer(pMainImg, L"Main");
		DrawImage(pImg);
	}

	std::wstring QtPZPMainWindow::OpenFile()
	{
		std::wstring strRes;

		CommandOpenFile commandOpenFile(strRes);
		commandOpenFile.Run();

		return strRes;
	}
	
	void QtPZPMainWindow::DrawImage(PzpCoreApp::ImageLayer* pImage)
	{
		if (!pImage)
			return;
		
		unsigned int nWidth = pImage->GetWidth();
		unsigned int nHeight = pImage->GetHeight();

		m_ImageManipulator.CreateNewImage(nWidth, nHeight);
		m_ImageManipulator.ChangeImage(0,0, nWidth, nHeight, pImage);
	}

	void QtPZPMainWindow::SetCore(PzpCoreApp::IPZPCore* pCore)
	{
		m_pCore = pCore;
	}
}
