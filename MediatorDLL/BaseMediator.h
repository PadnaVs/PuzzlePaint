#pragma once

#include "BaseMediatorComponent.h"
#include <string>
#include "Consts.h"

namespace PZPLib
{
	class BaseMediatorComponent;

	class MEDIATOR_DLL_EXPORT Mediator
	{
	public:
		virtual void Notify(BaseMediatorComponent* pComp, const std::string& strEvent, void* pData = nullptr) const = 0;
	};
}

