#pragma once
#include <string>
class IQtUI
{
public:
	virtual ~IQtUI() {}

	virtual void SendEventPushButton() = 0;
	virtual void GetEventText(const std::wstring& strText) = 0;
};

