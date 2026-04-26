#pragma once
#include "DLLHeader.h"
#include "framework.h"
#include "ImageLayer.h"

namespace PzpCoreApp
{
	class PUZZLEPAINTCORE_EXPORTS IPZPCore
	{
	public:
		virtual ~IPZPCore() {}

		virtual ImageLayer* LoadLayer(std::unique_ptr<ImageLayer>& pImage, const std::wstring& strName) = 0;
		virtual ImageLayer* ReadLayer(const std::wstring& strName) = 0;
	};
}

