#pragma once
#include <vector>
#include <memory>

namespace PzpCoreApp
{
	using ImageInHeap = std::unique_ptr<std::vector<std::vector<size_t>>>;
	class ImageLayer
	{
	public:
		ImageLayer();

		//забирает владение
		void SetPixelMap(ImageInHeap pPixMap);

		std::vector<std::vector<size_t>>* GetPixelMap();
	private:
		ImageInHeap m_pImage;
	};
}
