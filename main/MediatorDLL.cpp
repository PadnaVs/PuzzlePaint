#include "MediatorDLL.h"

MediatorDLL::MediatorDLL(PzpCoreApp::CoreMediatorComponent* pCore, PzpUI::UIMediatorComponent* pUI) : m_pCore(pCore), m_pUI(pUI)
{
	m_pCore->SetMediator(this);
	m_pUI->SetMediator(this);
}

void MediatorDLL::Notify(PZPLib::BaseMediatorComponent* sender, const std::string& event, void* pData /*= nullptr*/) const
{
	if (event == "A") 
	{
		this->m_pCore->DoB();
	}
	if (event == "C") 
	{
		wchar_t* pStr = static_cast<wchar_t*>(pData);
		const std::wstring& str(pStr);
		if (!str.empty()) 
			this->m_pUI->ShowText(str);
	}
}
