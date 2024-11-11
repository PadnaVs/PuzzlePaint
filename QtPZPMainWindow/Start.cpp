#include "Start.h"
#include "DI.h"

#include "QtPZPApplication.h"

void StartQtApp(int& argc, char** argv, int flags)
{
	DI<QtPZPApplication, QtPZPApplication>::AddSingleton(argc, argv, flags);


	QtPZPApplication* pApplication = DI<QtPZPApplication, QtPZPApplication>::GetSingleton();
	pApplication->ShowWindow();

	if (!pApplication->closingDown()) {
		pApplication->exec();
	}
}
