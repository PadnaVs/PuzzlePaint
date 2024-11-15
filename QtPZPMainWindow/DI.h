#pragma once
#include <memory>
#include <string>
#include <map>
#include "qtpzpmainwindow_global.h"

class QtPZPApplication;

template<class I, class T>
class QTDLL_EXPORT DI {
public:
	template<typename ...Args>
	static void AddSingleton(Args&... args) {
		const auto& name = std::string(typeid(T).name());
		if (singletones.find(name) == singletones.end())
			singletones[name] = std::make_unique<T>(args...);
	}

	static void RemoveSingleton() {
		const auto& name = std::string(typeid(T).name());
		auto it = singletones.find(name);
		if (singletones.end() != it) {
			singletones.erase(it);
		}
	}

	static I* GetSingleton() {
		const auto& name = std::string(typeid(T).name());
		if(singletones.end() != singletones.find(name))
			return singletones[name].get();
		return nullptr;
	}

	static T* GetConcreteSingleton() {
		T* pT = static_cast<T*>(GetSingleton());
		if (pT)
		{
			return pT;
		}
		return nullptr;
	}

private:
	static std::map<std::string, std::unique_ptr<I>> singletones;
};

template <class I, class T>
std::map<std::string, std::unique_ptr<I>> DI<I, T>::singletones;


QTDLL_EXPORT QtPZPApplication* GetPZPQtApplication();


