#pragma once
#include <iostream>
#include "../MediatorDLL/BaseMediatorComponent.h"
#include "qtpzpmainwindow_global.h"

namespace PzpUI
{
	class QTDLL_EXPORT UIMediatorComponent :
		public PZPLib::BaseMediatorComponent
	{
	public:
		void DoA();
	};
}
