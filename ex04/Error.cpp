#include "Error.hpp"
#include <iostream>

Error::Error(void)
	: _errorPrompt("Error: ")
{
}

void	Error::HandleArgumentCountError(void) const
{
	_PrintErrorMessage("Wrong argument count", "");
	std::cout << "File name, target word and new word are needed.\n";
	exit(0);
}

void	Error::HandleFilePathError(std::string wrongFilePath) const
{
	_PrintErrorMessage("Wrong file path", wrongFilePath);
	exit(0);
}

void	Error::HandleFileOpenError(std::string filePath) const
{
	_PrintErrorMessage("Opening file failed", filePath);
	exit(1);
}

void	Error::HandleTargetWordError(std::string wrongTargetWord) const
{
	_PrintErrorMessage("Wrong target word", wrongTargetWord);
	exit(0);
}



void	Error::_PrintErrorMessage(std::string errorMessage, std::string errorSource) const
{
	std::cout << _errorPrompt << errorMessage;
	if (errorSource == "")
		std::cout << std::endl;
	else
		std::cout << ": " << errorSource << std::endl;
}
