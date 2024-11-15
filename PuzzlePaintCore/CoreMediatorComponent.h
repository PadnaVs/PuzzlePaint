#pragma once
#include <iostream>
#include "../MediatorDLL/BaseMediatorComponent.h"
#include "Consts.h"

class PUZZLE_PAINT_DLL_EXPORT CoreMediatorComponent :
    public BaseMediatorComponent
{
public:
	CoreMediatorComponent();
	~CoreMediatorComponent();

	void DoB();
};

