#include "pch.h"
#include "ImageLayer.h"

namespace PzpCoreApp
{
	ImageLayer::ImageLayer() 
	{
	
	}

	void ImageLayer::SetPixelMap(ImageInHeap pPixMap)
	{
		m_pImage = std::move(pPixMap);
	}

	std::vector<std::vector<size_t>>* ImageLayer::GetPixelMap()
	{
		return m_pImage.get();
	}
}