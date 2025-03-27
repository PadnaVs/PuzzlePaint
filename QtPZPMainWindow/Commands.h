#pragma once
#include <string>

namespace PzpUI
{
	class ICommand 
	{
	public:
		ICommand() {}
		virtual ~ICommand() {}

		virtual bool isRun() = 0;
		virtual void Run() = 0;
	};

	class CommandOpenFile : public ICommand
	{
	public:
		CommandOpenFile(std::wstring& strResult);
		
		bool isRun() override;
		void Run() override;

	private:
		CommandOpenFile(CommandOpenFile& other);
		CommandOpenFile(CommandOpenFile&& other);
		CommandOpenFile& operator=(CommandOpenFile& other);
		CommandOpenFile& operator=(CommandOpenFile&& other);

		std::wstring& m_strResult;
	};
}
