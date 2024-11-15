#pragma once
#include "../PuzzlePaintCore/CoreMediatorComponent.h"
#include "../QtPZPMainWindow/UIMediatorComponent.h"
#include "../MediatorDLL/BaseMediator.h"

class MediatorDLL : public Mediator
{
public:
	MediatorDLL(CoreMediatorComponent* pCore, UIMediatorComponent* pUI) : m_pCore(pCore), m_pUI(pUI)
	{
		m_pCore->SetMediator(this);
		m_pUI->SetMediator(this);
	}

	void Notify(BaseMediatorComponent* sender, const std::string& event) const override
	{
		if (event == "A") {
			std::cout << "Mediator reacts on A and triggers following operations:\n";
			this->m_pCore->DoB();
		}
	}
private:
	CoreMediatorComponent* m_pCore;
	UIMediatorComponent* m_pUI;
};

