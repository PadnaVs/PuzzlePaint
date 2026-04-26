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

	void PZPCore::LoadImage(std::unique_ptr<ImageLayer>& pImage, const std::wstring& strName)
	{
		if (!pImage)
		{
			std::cout << "\nError core: Load field!\n";
			return;
		}
			
		m_arrLayer->emplace(strName, std::move(pImage));
	}

	ImageLayer* PZPCore::ReadLayer(const std::wstring& strName)
	{
		const auto& it = m_arrLayer->find(strName);
		if (it == m_arrLayer->end())
			return nullptr;

		return it->second.get();
	}
}
