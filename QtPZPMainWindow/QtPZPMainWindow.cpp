#include "QtPZPMainWindow.h"
#include "DI.h"
#include "QtPZPApplication.h"

namespace PzpUI
{
	QtPZPMainWindow::QtPZPMainWindow(QWidget* parent)
		: QWidget(parent)
	{
		ui.setupUi(this);

		connect(ui.pushButton, &QPushButton::clicked, this, &QtPZPMainWindow::slotPushButton);
	}

	QtPZPMainWindow::~QtPZPMainWindow()
	{

	}

	void QtPZPMainWindow::SetText(const std::wstring& strText)
	{
		ui.label->setText(QString::fromStdWString(strText));
	}

	void QtPZPMainWindow::slotPushButton()
	{
		QtPZPApplication* pApp = GetPZPQtApplication();
		if (!pApp)
			return;

		pApp->GetUIMediator()->DoA();
	}
}
