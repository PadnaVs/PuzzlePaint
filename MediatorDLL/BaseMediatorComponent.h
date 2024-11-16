#pragma once
#include "Consts.h"
#include "BaseMediator.h"
#include "pch.h"

namespace PZPLib
{
	class MEDIATOR_DLL_EXPORT BaseMediatorComponent
	{
	public:
		BaseMediatorComponent(Mediator* pMediator = nullptr);
		~BaseMediatorComponent();

		void SetMediator(Mediator* pMediator);

	protected:
		Mediator* m_pMediator;
	};
}
