#include "DI.h"
#include "QtPZPApplication.h"
#include "..\PuzzlePaintCore\PZPCore.h"

namespace PzpUI
{
	QtPZPApplication* GetPZPQtApplication(int& argc, char** argv, int flags)
	{
		PzpUI::DI<QtPZPApplication, QtPZPApplication>::AddSingleton(argc, argv, flags);
		return DI<QtPZPApplication, QtPZPApplication>::GetConcreteSingleton();
	}

	PzpCoreApp::IPZPCore* GetPZPCoreApplication() 
	{
		DI<PzpCoreApp::IPZPCore, PzpCoreApp::PZPCore>::AddSingleton();
		return DI<PzpCoreApp::IPZPCore, PzpCoreApp::PZPCore>::GetConcreteSingleton();
	}
}