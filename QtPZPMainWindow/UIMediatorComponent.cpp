#include "UIMediatorComponent.h"
#include "DI.h"
#include "QtPZPApplication.h"

namespace PzpUI
{
	void UIMediatorComponent::DoA()
	{
		m_pMediator->Notify(this, "A");
	}

	/*void UIMediatorComponent::ShowText(const std::wstring& strText)
	{
		QtPZPApplication* pApp = GetPZPQtApplication();
		if (!pApp)
			return;

		pApp->SetText(strText);
	}*/
}
