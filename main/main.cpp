#include "../QtPZPMainWindow/Start.h"
#include "MediatorDLL.h"
#include "../PuzzlePaintCore/Start.h"

int main(int argc, char* argv[])
{
	CreateCoreApp();
	CreateQtUIApp(argc, argv, 6);

	CoreMediatorComponent* pCoreMediator = GetCoreMediator();
	UIMediatorComponent* pMediatorUI = GetQtUIMediator();
	
	MediatorDLL mediatorDLL(pCoreMediator, pMediatorUI);

	ShowMainWindow();
	return 0;
}