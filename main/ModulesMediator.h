#pragma once
#include "ICore.h"
#include "IQtUI.h"

class ModulesMediator
{
public:
	enum eEventsQtWindow
	{
		eNoneQ = 0,
		eTestQ = 1 
	};

	enum eEventsCore
	{
		eNoneC = 0,
		eTestC = 1
	};

	ModulesMediator(ICore* pCore, IQtUI* pApplication);

	template<typename ...Args>
	void OnNotify(eEventsQtWindow eEvent, Args... args) 
	{
	
	};

	void OnNotify(eEventsCore eEvent) {};

	ICore* m_pCore;
	IQtUI* m_pApplication;
};

