#pragma once
class IQtUIApp
{
public:
	virtual ~IQtUIApp() = default;
	virtual void SendEventPushButton() = 0;
};

