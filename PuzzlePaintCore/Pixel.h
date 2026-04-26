#pragma once
#include <cstdint>
#include "DLLHeader.h"

namespace PzpCoreApp
{
	struct PUZZLEPAINTCORE_EXPORTS Pixel
	{
		uint32_t m_nR;
		uint32_t m_nG;
		uint32_t m_nB;
		uint32_t m_nAlpha;
	};
}

