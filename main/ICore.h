#pragma once
#include <string>
class ICore
{
public:
	virtual ~ICore() {};
	virtual const std::wstring& SendStr() = 0;
};

