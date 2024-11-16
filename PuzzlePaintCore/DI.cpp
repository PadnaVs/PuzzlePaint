#include "pch.h"
#include "DI.h"
#include "PZPCore.h"

namespace PzpCoreApp
{
	PUZZLE_PAINT_DLL_EXPORT PZPCore* GetCoreApplication()
	{
		return DI<PZPCore, PZPCore>::GetConcreteSingleton();
	}
}
