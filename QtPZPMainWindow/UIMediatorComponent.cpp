#include "UIMediatorComponent.h"
#include "DI.h"
#include "QtPZPApplication.h"

namespace PzpUI
{
	void UIMediatorComponent::LoadImage(std::vector<std::vector<std::vector<int>>>& arrPixelMap)
	{
		m_pMediator->Notify(this, "eventLoadImage", &arrPixelMap);
	}

	/*void UIMediatorComponent::ShowText(const std::wstring& strText)
	{
		QtPZPApplication* pApp = GetPZPQtApplication();
		if (!pApp)
			return;

		pApp->SetText(strText);
	}*/
}
