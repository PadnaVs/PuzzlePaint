#pragma once
#include <iostream>
#include "../MediatorDLL/BaseMediatorComponent.h"

class UIMediatorComponent :
    public BaseMediatorComponent
{
public:
	void DoA()
	{
		std::cout << "Component UI does A.\n";
		m_pMediator->Notify(this, "A");
	}
};

