#include "DI.h"
#include <conio.h>

int main(int argc, char* argv[])
{
	
	PzpUI::CreateQTApp(argc, argv, 6);
	PzpUI::CreateCoreApp();

	PzpUI::QtPZPApplication* pQTApp = PzpUI::GetPZPQtApplication();

	pQTApp->ShowWindow();

	if (!pQTApp->closingDown()) {
		pQTApp->exec();
	}

	return 0;
}