#pragma once
#include "DI.h"
#include "..\PuzzlePaintCore\PZPCore.h"

void CreateQTApp(int& argc, char** argv, const int& n);

void CreateCoreApp();

PzpCoreApp::IPZPCore* GetCore();

void ShowMainWindow();