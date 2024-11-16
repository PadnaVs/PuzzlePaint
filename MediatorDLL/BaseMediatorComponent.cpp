#include "pch.h"
#include "BaseMediatorComponent.h"

namespace PZPLib
{
	BaseMediatorComponent::BaseMediatorComponent(Mediator* pMediator /*= nullptr*/) : m_pMediator(pMediator)
	{

	}

	BaseMediatorComponent::~BaseMediatorComponent()
	{

	}

	void BaseMediatorComponent::SetMediator(Mediator* pMediator)
	{
		this->m_pMediator = pMediator;
	}
}
