#pragma once
#include "UICommandHandler.h"
#include <string>

namespace PzpUI
{
	class CommandOpenFile
	{
	public:
		CommandOpenFile(UICommandHandler& pCommandHandler);
		
		std::wstring Run();

	private:
		CommandOpenFile(CommandOpenFile& other);
		CommandOpenFile(CommandOpenFile&& other);
		CommandOpenFile& operator=(CommandOpenFile& other);
		CommandOpenFile& operator=(CommandOpenFile&& other);

		UICommandHandler& m_pCommandHandler;
	};
}
