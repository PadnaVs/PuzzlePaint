#pragma once

#ifdef QTPZPMAINWINDOW_LIB
#define QTDLL_EXPORT __declspec(dllexport)
#else
#define QTDLL_EXPORT __declspec(dllimport)
#endif



/*
#ifndef BUILD_STATIC
# if defined(QTPZPMAINWINDOW_LIB)
#  define QTDLL_EXPORT Q_DECL_EXPORT
# else
#  define QTDLL_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTDLL_EXPORT
#endif*/

