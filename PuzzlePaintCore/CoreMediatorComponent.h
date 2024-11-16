#pragma once
#include <iostream>
#include "../MediatorDLL/BaseMediatorComponent.h"
#include "Consts.h"

namespace PzpCoreApp
{
	class PUZZLE_PAINT_DLL_EXPORT CoreMediatorComponent :
		public PZPLib::BaseMediatorComponent
	{
	public:
		CoreMediatorComponent();
		~CoreMediatorComponent();

		void DoB();
	};
}

