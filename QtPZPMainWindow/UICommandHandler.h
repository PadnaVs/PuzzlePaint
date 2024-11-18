#pragma once
#include <string>


namespace PzpUI
{
	class UICommandHandler
	{
	public:
		UICommandHandler();
		~UICommandHandler();
	
		std::wstring OpenFile();
	
	private:
		UICommandHandler(UICommandHandler& other);
		UICommandHandler(UICommandHandler&& other);
		UICommandHandler& operator=(UICommandHandler& other);
		UICommandHandler& operator=(UICommandHandler&& other);
	};
}

