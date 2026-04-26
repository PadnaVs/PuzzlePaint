#include "DI.h"

int main(int argc, char* argv[])
{
	PzpUI::QtPZPApplication* pQTApp = PzpUI::GetPZPQtApplication(argc, argv, 6);

	pQTApp->ShowWindow();

	return 0;
}