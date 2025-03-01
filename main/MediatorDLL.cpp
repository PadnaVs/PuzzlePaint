#include "MediatorDLL.h"
#include <memory>

MediatorDLL::MediatorDLL(PzpCoreApp::CoreMediatorComponent* pCore, PzpUI::UIMediatorComponent* pUI) : m_pCore(pCore), m_pUI(pUI)
{
	if (!m_pCore || !m_pUI)
		return;

	m_pCore->SetMediator(this);
	m_pUI->SetMediator(this);
}

void MediatorDLL::Notify(PZPLib::BaseMediatorComponent* sender, const std::string& strEvent, void* pData /*= nullptr*/) const
{
	if (!m_pCore)
		return;

	if (strEvent == "eventLoadImage")
	{
		std::vector<std::vector<std::vector<int>>>* pArrPixelMap = (std::vector<std::vector<std::vector<int>>>*)(pData);
		if (!pArrPixelMap)
			return;

		m_pCore->LoadImage(pArrPixelMap);
	}
	else if (strEvent == "eventDrawImage")
	{
		std::vector<std::vector<std::vector<int>>>* pArrPixelMap = (std::vector<std::vector<std::vector<int>>>*)(pData);
		if (!pArrPixelMap)
			return;
		
		m_pUI->DrawImage(pArrPixelMap);
	}
}
