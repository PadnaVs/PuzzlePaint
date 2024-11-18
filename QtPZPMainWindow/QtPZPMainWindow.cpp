#include "QtPZPMainWindow.h"
#include "QtPZPApplication.h"
#include "Commands.h"

namespace PzpUI
{
	QtPZPMainWindow::QtPZPMainWindow(QWidget* parent)
		: QWidget(parent), m_pButOpenFile(nullptr)
	{
		ui.setupUi(this);

		m_pButOpenFile = ui.m_OpenImgBut;
		m_pLabelImageOut = ui.m_ImageOut;

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

		QPixmap myPixmap(qStrFileName);
		m_pLabelImageOut->setPixmap(myPixmap);
	}

	/*void QtPZPMainWindow::slotPushButton()
	{
		QtPZPApplication* pApp = GetPZPQtApplication();
		if (!pApp)
			return;

		pApp->GetUIMediator()->DoA();
	}*/
}
