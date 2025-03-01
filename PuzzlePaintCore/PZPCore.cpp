#include "pch.h"
#include "PZPCore.h"
#include <iostream>

namespace PzpCoreApp
{
	PZPCore::PZPCore()
	{

	}

	PZPCore::~PZPCore()
	{

	}

	void PZPCore::LoadImage(std::vector<std::vector<std::vector<int>>>* pArrPixelMap)
	{
		if (!pArrPixelMap)
		{
			std::cout << "\nError core: Load field!\n";
			return;
		}
			
		m_pixelMapOgirn = *pArrPixelMap;

		if (!m_pixelMapOgirn.size()) 
		{
			std::cout << "\nError core: Load field!\n";
			return;
		}
		else 
		{
			std::cout << "\n\Load nice!\n";
			m_coreMediator.DrawImage(m_pixelMapOgirn);
		}
	}
}
