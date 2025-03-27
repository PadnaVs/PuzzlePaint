#include "Commands.h"
#include "QFileDialog"
#include "string"

PzpUI::CommandOpenFile::CommandOpenFile(std::wstring& strResult) : m_strResult(strResult)
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

PzpUI::CommandOpenFile::CommandOpenFile(CommandOpenFile&& other) : m_strResult(other.m_strResult)
{

}

PzpUI::CommandOpenFile::CommandOpenFile(CommandOpenFile& other) : m_strResult(other.m_strResult)
{

}

bool PzpUI::CommandOpenFile::isRun()
{
	return true;
}

void PzpUI::CommandOpenFile::Run()
{
	m_strResult = QFileDialog::getOpenFileName().toStdWString();
}
