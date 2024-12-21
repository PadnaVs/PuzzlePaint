#pragma once
#include <iostream>
#include <vector>
#include "../MediatorDLL/BaseMediatorComponent.h"
#include "qtpzpmainwindow_global.h"

namespace PzpUI
{
	class QTDLL_EXPORT UIMediatorComponent :
		public PZPLib::BaseMediatorComponent
	{
	public:
		void LoadImage(std::vector<std::vector<std::vector<int>>>& arrPixelMap);
	};
}
