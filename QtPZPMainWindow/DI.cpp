#include "DI.h"
#include "QtPZPApplication.h"
#include "..\PuzzlePaintCore\PZPCore.h"

namespace PzpUI
{
	QtPZPApplication* GetPZPQtApplication()
	{
		return DI<QtPZPApplication, QtPZPApplication>::GetConcreteSingleton();
	}

	PzpCoreApp::IPZPCore* GetPZPCoreApplication() 
	{
		return DI<PzpCoreApp::IPZPCore, PzpCoreApp::PZPCore>::GetConcreteSingleton();
	}
}