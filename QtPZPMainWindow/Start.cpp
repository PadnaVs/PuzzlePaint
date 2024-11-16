#include "Start.h"
#include "DI.h"
#include "QtPZPApplication.h"

void CreateQtUIApp(int& argc, char** argv, int flags)
{
	PzpUI::DI<PzpUI::QtPZPApplication, PzpUI::QtPZPApplication>::AddSingleton(argc, argv, flags);
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
};


QTDLL_EXPORT PzpUI::UIMediatorComponent* GetQtUIMediator()
{
	PzpUI::QtPZPApplication* pApplication = PzpUI::DI<PzpUI::QtPZPApplication, PzpUI::QtPZPApplication>::GetSingleton();
	if (!pApplication)
		return nullptr;

	return pApplication->GetUIMediator();
}

