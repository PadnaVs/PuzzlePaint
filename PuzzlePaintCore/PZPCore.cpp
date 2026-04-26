#include "pch.h"
#include "PZPCore.h"
#include <iostream>

namespace PzpCoreApp
{
	PZPCore::PZPCore() : m_arrLayer(std::make_unique<std::map<std::wstring, std::unique_ptr<ImageLayer>>>())
	{

	}

	PZPCore::~PZPCore()
	{

	}

	ImageLayer* PZPCore::LoadLayer(std::unique_ptr<ImageLayer>& pImage, const std::wstring& strName)
	{
		ImageLayer* pImgRes = nullptr;

		if (!pImage)
		{
			std::cout << "\nError core: Load field!\n";
			return pImgRes;
		}
		
		auto it = m_arrLayer->find(strName);
		if (it != m_arrLayer->end())
		{
			it->second = std::move(pImage);
			pImgRes = it->second.get();
		}
		else 
		{
			auto it = m_arrLayer->emplace(strName, std::move(pImage));
			pImgRes = it.first->second.get();
		}
		
		return pImgRes;
	}

	ImageLayer* PZPCore::ReadLayer(const std::wstring& strName)
	{
		const auto& it = m_arrLayer->find(strName);
		if (it == m_arrLayer->end())
			return nullptr;

		return it->second.get();
	}
}
