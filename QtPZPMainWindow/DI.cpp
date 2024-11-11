#include "DI.h"
#include "QtPZPApplication.h"


QTDLL_EXPORT QtPZPApplication* GetPZPQtApplication()
{
	return DI<QtPZPApplication, QtPZPApplication>::GetConcreteSingletone();
}
