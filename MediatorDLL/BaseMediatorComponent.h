#pragma once
#include "pch.h"
#include "Consts.h"
#include "BaseMediator.h"

class MEDIATOR_DLL_EXPORT BaseMediatorComponent
{
public:
	BaseMediatorComponent(Mediator* pMediator = nullptr);
	~BaseMediatorComponent();

	void SetMediator(Mediator* pMediator);

protected:
	Mediator* m_pMediator;
};
