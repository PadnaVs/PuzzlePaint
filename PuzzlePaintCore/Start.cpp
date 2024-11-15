#include "pch.h"
#include "Start.h"
#include "DI.h"
#include "PZPCore.h"

PUZZLE_PAINT_DLL_EXPORT void CreateCoreApp()
{
	DI<PZPCore, PZPCore>::AddSingleton();
}

PUZZLE_PAINT_DLL_EXPORT CoreMediatorComponent* GetCoreMediator()
{
	PZPCore* pApplication = DI<PZPCore, PZPCore>::GetConcreteSingleton();
	if (!pApplication)
		return nullptr;

	return &pApplication->m_coreMediator;
}
