#pragma once
#include "qtpzpmainwindow_global.h"
#include "../main/IQtUIApp.h"

QTDLL_EXPORT void CreateQtUIApp(int& argc, char** argv, int flags);
QTDLL_EXPORT void ShowMainWindow();
QTDLL_EXPORT IQtUIApp* GetQtUIMediator();
