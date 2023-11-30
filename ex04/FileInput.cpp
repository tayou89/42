#include "FileInput.hpp"

FileInput::FileInput(void)
	: _filePath("")
{
}

FileInput::~FileInput(void)
{
	if (_fileStream.is_open() == true)
		_fileStream.close();
}

void	FileInput::SetFilePath(const std::string filePath)
{
	if (filePath == "")
		_error.HandleFilePathError(filePath);
	else
		this->_filePath = filePath;
}

void	FileInput::OpenFile(void)
{
	_fileStream.open(_filePath.c_str());
	if (_fileStream.is_open() == false)
		_error.HandleFileOpenError(_filePath);
}

void	FileInput::CloseFile(void)
{
	_fileStream.close();
}

std::string	FileInput::ReadFile(void)
{
	std::string	string;

	std::getline(_fileStream, string, '\0');
	return (string);
}

int	FileInput::IsEndOfFile(void) const
{
	return (_fileStream.eof());
}
