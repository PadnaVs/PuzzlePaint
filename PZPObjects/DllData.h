#pragma once

#ifdef PZPObjects
#define PZPObjects_EXPORT __declspec(dllexport)
#else
#define PZPObjects_EXPORT __declspec(dllimport)
#endif
