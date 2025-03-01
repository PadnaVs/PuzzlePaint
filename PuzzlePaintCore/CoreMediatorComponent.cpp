#include "pch.h"
#include "CoreMediatorComponent.h"
#include "PZPCore.h"
#include "DI.h"

namespace PzpCoreApp 
{
	CoreMediatorComponent::CoreMediatorComponent() : PZPLib::BaseMediatorComponent()
	{

	}

	CoreMediatorComponent::~CoreMediatorComponent()
	{

	}

	void CoreMediatorComponent::LoadImage(std::vector<std::vector<std::vector<int>>>* pArrPixelMap)
	{
		PZPCore* pPZPCore = GetCoreApplication();
		if (!pPZPCore)
			return;

		pPZPCore->LoadImage(pArrPixelMap);
	}

	void CoreMediatorComponent::DrawImage(std::vector<std::vector<std::vector<int>>>& arrPixelMap)
	{
		m_pMediator->Notify(this, "eventDrawImage", &arrPixelMap);
	}

}

