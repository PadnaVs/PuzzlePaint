#pragma once
#include <iostream>
#include <vector>
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

		void LoadImage(std::vector<std::vector<std::vector<int>>>* pArtPixelMap);

		void DrawImage(std::vector<std::vector<std::vector<int>>>& arrPixelMap);
	};
}

