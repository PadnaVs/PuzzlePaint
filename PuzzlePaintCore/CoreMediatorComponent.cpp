#include "pch.h"
#include "CoreMediatorComponent.h"
#include "PZPCore.h"
#include "DI.h"

CoreMediatorComponent::CoreMediatorComponent() : BaseMediatorComponent()
{

}

CoreMediatorComponent::~CoreMediatorComponent()
{

}

void CoreMediatorComponent::DoB()
{
	PZPCore* pPZPCore = GetCoreApplication();
	if (!pPZPCore)
		return;

	m_pMediator->Notify(this, "C", &pPZPCore->GetText()[0]);
}
