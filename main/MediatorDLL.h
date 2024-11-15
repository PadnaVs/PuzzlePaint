#pragma once
#include "../PuzzlePaintCore/CoreMediatorComponent.h"
#include "../QtPZPMainWindow/UIMediatorComponent.h"
#include "../MediatorDLL/BaseMediator.h"

class MediatorDLL : public Mediator
{
public:
	MediatorDLL(CoreMediatorComponent* pCore, UIMediatorComponent* pUI);

	void Notify(BaseMediatorComponent* sender, const std::string& event, void* pData = nullptr) const override;
private:
	CoreMediatorComponent* m_pCore;
	UIMediatorComponent* m_pUI;
};

