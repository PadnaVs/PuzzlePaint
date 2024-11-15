#include "Start.h"
#include "DI.h"

#include "QtPZPApplication.h"

void CreateQtUIApp(int& argc, char** argv, int flags)
{
	DI<QtPZPApplication, QtPZPApplication>::AddSingleton(argc, argv, flags);
}

void ShowMainWindow() 
{
	QtPZPApplication* pApplication = DI<QtPZPApplication, QtPZPApplication>::GetSingleton();
	if (!pApplication)
		return;

	pApplication->ShowWindow();

	if (!pApplication->closingDown()) {
		pApplication->exec();
	}
};


QTDLL_EXPORT UIMediatorComponent* GetQtUIMediator()
{
	QtPZPApplication* pApplication = DI<QtPZPApplication, QtPZPApplication>::GetSingleton();
	if (!pApplication)
		return nullptr;

	return pApplication->GetUIMediator();
}

