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

		void SetWidth(const size_t& w)
		{
			m_nWidth = w;
		}

		size_t GetWidth() 
		{
			return m_nWidth;
		}
		
		void SetHeight(const size_t& h)
		{
			m_nHeight = h;
		}

		size_t GetHeight()
		{
			return m_nHeight;
		}

	private:
		size_t m_nWidth;
		size_t m_nHeight;

		ImageInHeap m_pImage;
	};
}
