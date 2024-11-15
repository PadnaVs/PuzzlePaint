#pragma once

#ifdef PUZZLEPAINTCORE_EXPORTS
#define PUZZLE_PAINT_DLL_EXPORT __declspec(dllexport)
#else
#define PUZZLE_PAINT_DLL_EXPORT __declspec(dllimport)
#endif