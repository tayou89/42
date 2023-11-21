#include "FileInput.hpp"

FileInput::FileInput(void)
	: _filePath("")
{
}

void	FileInput::SetFilePath(const std::string filePath)
{
	this->_filePath = filePath;
}

void	FileInput::SetFileStream(void)
{
	_fileStream.open(_filePath);
}

std::string	FileInput::ReadLine(void)
{
	std::string	fileLine;

	std::getline(_fileStream, fileLine);
	return (fileLine);
}

int	FileInput::IsFileStreamSet(void) const;
{
	return (_fileStream.is_open());
}

std::string FileInput::IsEndOfFile(void) const;
{
	return (_fileStream.eof());
}
