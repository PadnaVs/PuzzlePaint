#include "pch.h"
#include "CoreMediatorComponent.h"

CoreMediatorComponent::CoreMediatorComponent() : BaseMediatorComponent()
{

}

CoreMediatorComponent::~CoreMediatorComponent()
{

}

void CoreMediatorComponent::DoB()
{
	std::cout << "Component Core does B.\n";
	m_pMediator->Notify(this, "B");
}
