#pragma once

#include "BaseMediatorComponent.h"
#include <string>
#include "Consts.h"

class BaseMediatorComponent;
class MEDIATOR_DLL_EXPORT Mediator
{
public:
	virtual void Notify(BaseMediatorComponent* pComp, const std::string& strEvent) const = 0;
};
