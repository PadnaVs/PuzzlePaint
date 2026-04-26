#include "Start.h"
#include <conio.h>

int main(int argc, char* argv[])
{
	CreateCoreApp();
	CreateQTApp(argc, argv, 6);
	
	ShowMainWindow();

	return 0;
}