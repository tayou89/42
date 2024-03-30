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
	this->_filePath = filePath;
}

std::string	FileInput::GetFilePath(void) const
{
	return (_filePath);
}

void	FileInput::OpenFile(void)
{
	_fileStream.open(_filePath.c_str());
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

int	FileInput::IsFileOpen(void) const
{
	return (_fileStream.is_open());
}

int	FileInput::IsEndOfFile(void) const
{
	return (_fileStream.eof());
}
