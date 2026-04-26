#pragma once
#include "framework.h"
#include "IPZPCore.h"

namespace PzpCoreApp
{
	class PUZZLEPAINTCORE_EXPORTS PZPCore : public IPZPCore
	{

	public:
		PZPCore();
		~PZPCore();

		void LoadImage(std::unique_ptr<ImageLayer>& pImage, const std::wstring& strName) override;
		
		ImageLayer* ReadLayer(const std::wstring& strName) override;

	private:
		std::unique_ptr<std::map<std::wstring, std::unique_ptr<ImageLayer>>> m_arrLayer;
	};
}
