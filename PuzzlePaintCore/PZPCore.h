#pragma once
#include "DI.h"
#include "CoreMediatorComponent.h"

namespace PzpCoreApp
{
	class PZPCore
	{
		template <class I, class T>
		friend class DI;

	public:
		PZPCore() : m_strType(L"Core Job")
		{

		}

		~PZPCore()
		{

		}

		std::wstring& GetText();

		CoreMediatorComponent m_coreMediator;
		std::wstring m_strType;
	};
}
