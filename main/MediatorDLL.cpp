#include "MediatorDLL.h"
#include <memory>

MediatorDLL::MediatorDLL(PzpCoreApp::CoreMediatorComponent* pCore, PzpUI::UIMediatorComponent* pUI) : m_pCore(pCore), m_pUI(pUI)
{
	m_pCore->SetMediator(this);
	m_pUI->SetMediator(this);
}

void MediatorDLL::Notify(PZPLib::BaseMediatorComponent* sender, const std::string& event, void* pData /*= nullptr*/) const
{
	if (event == "eventLoadImage") 
	{
		std::vector<std::vector<std::vector<int>>>* pArrPixelMap = (std::vector<std::vector<std::vector<int>>>*)(pData);
		if (!pArrPixelMap)
			return;

		this->m_pCore->LoadImage(pArrPixelMap);
	}
}
