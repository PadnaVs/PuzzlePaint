#pragma once
#include "../PuzzlePaintCore/CoreMediatorComponent.h"
#include "../QtPZPMainWindow/UIMediatorComponent.h"
#include "../MediatorDLL/BaseMediator.h"

class MediatorDLL : public PZPLib::Mediator
{
public:
	MediatorDLL(PzpCoreApp::CoreMediatorComponent* pCore, PzpUI::UIMediatorComponent* pUI);

	void Notify(PZPLib::BaseMediatorComponent* sender, const std::string& strEvent, void* pData = nullptr) const override;
private:
	PzpCoreApp::CoreMediatorComponent* m_pCore;
	PzpUI::UIMediatorComponent* m_pUI;
};

