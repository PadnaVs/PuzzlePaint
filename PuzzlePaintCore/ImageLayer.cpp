#include "pch.h"
#include "ImageLayer.h"

namespace PzpCoreApp
{
	ImageLayer::ImageLayer() : m_nWidth(0), m_nHeight(0)
	{
	
	}

	void ImageLayer::SetPixelMap(ImageInHeap pPixMap)
	{
		m_pImage = std::move(pPixMap);
	}

	std::vector<std::vector<Pixel>>* ImageLayer::GetPixelMap()
	{
		return m_pImage.get();
	}
}