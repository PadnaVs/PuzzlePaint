#pragma once

#ifdef MEDIATORDLL_EXPORTS
#define MEDIATOR_DLL_EXPORT __declspec(dllexport)
#else
#define MEDIATOR_DLL_EXPORT __declspec(dllimport)
#endif
