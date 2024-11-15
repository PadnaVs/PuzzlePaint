#pragma once
#include "Consts.h"
#include <string>
#include "CoreMediatorComponent.h"

class PUZZLE_PAINT_DLL_EXPORT Test
{
public:
	Test() {}
	~Test() {}

	std::wstring GetStrTest();

	CoreMediatorComponent m_coreMediator;
};

