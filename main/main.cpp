#include "../QtPZPMainWindow/Start.h"
#include "../PuzzlePaintCore/Test.h"
#include "MediatorDLL.h"

int main(int argc, char* argv[])
{
	CreateQtUIApp(argc, argv, 6);

	Test ts;

	UIMediatorComponent* pMediatorUI = GetQtUIMediator();

	MediatorDLL mediatorDLL(&ts.m_coreMediator, pMediatorUI);

	ShowMainWindow();
	return 0;
}