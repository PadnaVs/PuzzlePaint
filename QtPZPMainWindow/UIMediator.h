#pragma once
#include <string>
#include "../main/IQtUIApp.h"

class UIMediator : public IQtUIApp
{
public:
	virtual ~UIMediator() {};

	virtual void SendEventPushButton();
};


