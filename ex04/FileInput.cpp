#include "FileInput.hpp"

FileInput::FileInput(void)
	: _filePath("")
{
}

std::string	FileInput::GetFilePath(void) const
{
	return (_filePath);
}

void	FileInput::SetFilePath(const std::string filePath)
{
	if (filePath == "")
		_error.HandleFilePathError(filePath);
	else
		this->_filePath = filePath;
}

void	FileInput::SetFileStream(void)
{
	_fileStream.open(_filePath.c_str());
	if (_fileStream.is_open() == false)
		_error.HandleFileOpenError(_filePath);
}

std::string	FileInput::ReadLine(void)
{
	std::string	fileLine;

	std::getline(_fileStream, fileLine, '\0');
	return (fileLine);
}

int	FileInput::IsEndOfFile(void) const
{
	return (_fileStream.eof());
}
