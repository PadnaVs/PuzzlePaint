#include "../QtPZPMainWindow/Start.h"

int main(int argc, char* argv[])
{
	CreateQtUIApp(argc, argv, 6);

	IQtUIApp* pMediatorUI = GetQtUIMediator();

	ShowMainWindow();
	return 0;
}