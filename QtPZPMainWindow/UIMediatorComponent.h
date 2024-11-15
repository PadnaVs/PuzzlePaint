#pragma once
#include <iostream>
#include "../MediatorDLL/BaseMediatorComponent.h"
#include "qtpzpmainwindow_global.h"

class QTDLL_EXPORT UIMediatorComponent :
    public BaseMediatorComponent
{
public:
	void DoA();
	void ShowText(const std::wstring& strText);
};

