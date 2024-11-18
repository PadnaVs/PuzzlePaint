#include "Commands.h"

PzpUI::CommandOpenFile::CommandOpenFile(UICommandHandler& pCommandHandler) : m_pCommandHandler(pCommandHandler)
{

}

PzpUI::CommandOpenFile& PzpUI::CommandOpenFile::operator=(CommandOpenFile&& other)
{
	return other;
}

PzpUI::CommandOpenFile& PzpUI::CommandOpenFile::operator=(CommandOpenFile& other)
{
	return other;
}

PzpUI::CommandOpenFile::CommandOpenFile(CommandOpenFile&& other) : m_pCommandHandler(other.m_pCommandHandler)
{

}

PzpUI::CommandOpenFile::CommandOpenFile(CommandOpenFile& other) : m_pCommandHandler(other.m_pCommandHandler)
{

}

std::wstring PzpUI::CommandOpenFile::Run()
{
	return m_pCommandHandler.OpenFile();
}
