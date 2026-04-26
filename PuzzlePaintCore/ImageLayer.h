#pragma once
#include "framework.h"
#include "Pixel.h"
#include "DLLHeader.h"

namespace PzpCoreApp
{
	using ImageInHeap = PUZZLEPAINTCORE_EXPORTS std::unique_ptr<std::vector<std::vector<Pixel>>>;
	class PUZZLEPAINTCORE_EXPORTS ImageLayer
	{
	public:
		ImageLayer();

		//забирает владение
		void SetPixelMap(ImageInHeap pPixMap);

		std::vector<std::vector<Pixel>>* GetPixelMap();
	private:
		ImageInHeap m_pImage;
	};
}
