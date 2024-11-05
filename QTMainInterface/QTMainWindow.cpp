#include "QTMainWindow.h"
#include "../PuzzlePaintCore/Test.h"

QTMainWindow::QTMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Test testDll;

	QString qStr = QString::fromStdWString(testDll.GetStrTest());
	
	QLabel* lb = new QLabel(this);
	lb->setLineWidth(1000);
	lb->setTextFormat(Qt::AutoText);
	lb->setText(qStr);
	
}

QTMainWindow::~QTMainWindow()
{}
