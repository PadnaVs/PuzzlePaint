#pragma once
#include <memory>
#include <string>
#include <map>
#include "Consts.h"

namespace PzpCoreApp
{
	class PZPCore;

	template<class I, class T>
	class PUZZLE_PAINT_DLL_EXPORT DI
	{
	public:
		template<typename...Args>
		static void AddSingleton(Args&... args)
		{
			const std::string& strName = std::string(typeid(T).name());
			if (singletones.find(strName) == singletones.end())
				singletones[strName] = std::make_unique<T>(args...);
		}

		static void RemoveSingleton()
		{
			const std::string& strName = std::string(typeid(T).name());
			auto it = singletones.find(strName);
			if (it != singletones.end())
				singletones.erase(it);
		}

		static I* GetSingleton()
		{
			const std::string& strName = std::string(typeid(T).name());
			if (singletones.find(strName) != singletones.end())
				return singletones[strName].get();
			return nullptr;
		}

		static T* GetConcreteSingleton()
		{
			T* pSing = static_cast<T*>(GetSingleton());
			if (pSing)
				return pSing;
			return nullptr;
		}

	private:
		static std::map<std::string, std::unique_ptr<I>> singletones;
	};

	template<class I, class T>
	std::map<std::string, std::unique_ptr<I>> DI<I, T>::singletones;

	PUZZLE_PAINT_DLL_EXPORT PZPCore* GetCoreApplication();
}