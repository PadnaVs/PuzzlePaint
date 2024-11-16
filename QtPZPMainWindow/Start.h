#pragma once
#include "qtpzpmainwindow_global.h"
#include "UIMediatorComponent.h"

QTDLL_EXPORT void CreateQtUIApp(int& argc, char** argv, int flags);
QTDLL_EXPORT void ShowMainWindow();
QTDLL_EXPORT PzpUI::UIMediatorComponent* GetQtUIMediator();