#include "DI.h"
#include "QtPZPApplication.h"

namespace PzpUI
{
	QTDLL_EXPORT QtPZPApplication* GetPZPQtApplication()
	{
		return DI<QtPZPApplication, QtPZPApplication>::GetConcreteSingleton();
	}
}