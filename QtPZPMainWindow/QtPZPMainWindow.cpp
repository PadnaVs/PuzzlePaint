#include "QtPZPMainWindow.h"
#include "DI.h"
#include "QtPZPApplication.h"

QtPZPMainWindow::QtPZPMainWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, this, &QtPZPMainWindow::slotPushButton);
}

QtPZPMainWindow::~QtPZPMainWindow()
{

}

void QtPZPMainWindow::slotPushButton()
{
	QtPZPApplication* pApp = GetPZPQtApplication();
	if (!pApp)
		return;

	pApp->GetUIMediator()->DoA();
}

