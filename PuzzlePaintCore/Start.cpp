#include "pch.h"
#include "Start.h"
#include "DI.h"
#include "PZPCore.h"

PUZZLE_PAINT_DLL_EXPORT void CreateCoreApp()
{
	PzpCoreApp::DI<PzpCoreApp::PZPCore, PzpCoreApp::PZPCore>::AddSingleton();
}

PUZZLE_PAINT_DLL_EXPORT PzpCoreApp::CoreMediatorComponent* GetCoreMediator()
{
	PzpCoreApp::PZPCore* pApplication = PzpCoreApp::DI<PzpCoreApp::PZPCore, PzpCoreApp::PZPCore>::GetConcreteSingleton();
	if (!pApplication)
		return nullptr;

	return &pApplication->m_coreMediator;
}
