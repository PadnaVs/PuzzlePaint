#include "UICommandHandler.h"
#include "QString"
#include "QFileDialog"

PzpUI::UICommandHandler::UICommandHandler()
{

}

PzpUI::UICommandHandler& PzpUI::UICommandHandler::operator=(UICommandHandler& other)
{
	return other;
}

PzpUI::UICommandHandler& PzpUI::UICommandHandler::operator=(UICommandHandler&& other)
{
	return other;
}

PzpUI::UICommandHandler::UICommandHandler(UICommandHandler&& other)
{

}

PzpUI::UICommandHandler::UICommandHandler(UICommandHandler& other)
{

}

PzpUI::UICommandHandler::~UICommandHandler()
{

}

std::wstring PzpUI::UICommandHandler::OpenFile()
{
	return QFileDialog::getOpenFileName().toStdWString();
}
