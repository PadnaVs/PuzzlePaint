#pragma once
#include "DI.h"
#include "CoreMediatorComponent.h"
#include <vector>

namespace PzpCoreApp
{
	class PZPCore
	{
		template <class I, class T>
		friend class DI;

	public:
		PZPCore();
		~PZPCore();

		void LoadImage(std::vector<std::vector<std::vector<int>>>* arrPixelMap);
		
		std::vector<std::vector<std::vector<int>>>* ReadImage() 
		{
			return &m_pixelMapOgirn;
		}

		CoreMediatorComponent m_coreMediator;

	private:
		std::vector<std::vector<std::vector<int>>> m_pixelMapOgirn;
	};
}
