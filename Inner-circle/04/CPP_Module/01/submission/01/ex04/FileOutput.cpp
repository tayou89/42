#include "FileOutput.hpp"

FileOutput::FileOutput(void)
	: _filePath("")
{
}

std::string	FileOutput::GetFilePath(void) const
{
	return (_filePath);
}

void	FileOutput::SetFilePath(const std::string filePath)
{
	this->_filePath = filePath;
}

void	FileOutput::SetFileStream(void)
{
	_fileStream.open(_filePath.c_str());
	if (_fileStream.is_open() == false)
		_error.HandleFileOpenError(_filePath);
}

void	FileOutput::WriteLine(const std::string line)
{
	if (line != "")
		_fileStream << line << std::endl;
}
