#include "QtPZPMainWindow.h"

QtPZPMainWindow::QtPZPMainWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//Почему то не работает
	connect(ui.pushButton, SIGNAL(ui.pushButton->click()), this, SLOT(slotPushButton()));
}

QtPZPMainWindow::~QtPZPMainWindow()
{}

void QtPZPMainWindow::slotPushButton()
{
	signalPushButton();
}

