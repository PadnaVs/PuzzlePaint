#pragma once
#define PUZZLE_PAINT_DLL_EXPORT __declspec(dllexport) 

class PUZZLE_PAINT_DLL_EXPORT Test
{
public:
	Test() {}
	~Test() {}

	std::wstring GetStrTest();
};

