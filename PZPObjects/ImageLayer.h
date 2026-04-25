#pragma once
#include <vector>
#include <memory>
#include "DLLdata.h"
#include "Pixel.h"

namespace PzpObjects
{
	using ImageInHeap = std::unique_ptr<std::vector<std::vector<Pixel>>>;
	class PZPObjects_EXPORT ImageLayer
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
