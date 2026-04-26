
#include "Start.h"

void CreateQTApp(int& argc, char** argv, const int& n)
{
	PzpUI::DI<PzpUI::QtPZPApplication, PzpUI::QtPZPApplication>::AddSingleton(argc, argv, n);
}

void CreateCoreApp()
{
	PzpUI::DI<PzpCoreApp::IPZPCore, PzpCoreApp::PZPCore>::AddSingleton();
}

PzpCoreApp::IPZPCore* GetCore() 
{
	return PzpUI::DI<PzpCoreApp::IPZPCore, PzpCoreApp::PZPCore>::GetSingleton();
}

void ShowMainWindow()
{
	PzpUI::QtPZPApplication* pApplication = PzpUI::DI<PzpUI::QtPZPApplication, PzpUI::QtPZPApplication>::GetSingleton();
	if (!pApplication)
		return;

	pApplication->ShowWindow();

	if (!pApplication->closingDown()) {
		pApplication->exec();
	}
}
