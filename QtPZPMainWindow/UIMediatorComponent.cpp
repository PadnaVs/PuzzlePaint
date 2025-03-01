#include "UIMediatorComponent.h"
#include "DI.h"
#include "QtPZPApplication.h"

namespace PzpUI
{
	void UIMediatorComponent::LoadImage(std::vector<std::vector<std::vector<int>>>& arrPixelMap)
	{
		m_pMediator->Notify(this, "eventLoadImage", &arrPixelMap);
	}

	void UIMediatorComponent::DrawImage(std::vector<std::vector<std::vector<int>>>* pArrPixelMap)
	{
		QtPZPApplication* pApp = GetPZPQtApplication();
		if (!pApp)
			return;

		pApp->GetPZPMainWindow().DrawImage(pArrPixelMap);
	}

}
