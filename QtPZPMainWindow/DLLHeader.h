#pragma once

#ifdef QTPZPMAINWINDOW_LIB
#define QTDLL_EXPORT __declspec(dllexport)
#else
#define QTDLL_EXPORT __declspec(dllimport)
#endif
