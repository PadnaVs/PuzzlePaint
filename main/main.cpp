#include "../QtPZPMainWindow/Start.h"
#include "MediatorDLL.h"
#include "../PuzzlePaintCore/Start.h"

int main(int argc, char* argv[])
{
	CreateCoreApp();
	CreateQtUIApp(argc, argv, 6);

	PzpCoreApp::CoreMediatorComponent* pCoreMediator = GetCoreMediator();
	PzpUI::UIMediatorComponent* pMediatorUI = GetQtUIMediator();
	
	MediatorDLL mediatorDLL(pCoreMediator, pMediatorUI);

	ShowMainWindow();
	return 0;
}