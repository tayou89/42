#include "FileOutput.hpp"

FileOutput::FileOutput(void)
	: _filePath("")
{
}

FileOutput::~FileOutput(void)
{
	if (_fileStream.is_open() == true)
		_fileStream.close();
}

void	FileOutput::SetFilePath(const std::string filePath)
{
	this->_filePath = filePath;
}

std::string	FileOutput::GetFilePath(void) const
{
	return (_filePath);
}

void	FileOutput::OpenFile(void)
{
	_fileStream.open(_filePath.c_str());
}

int	FileOutput::IsFileOpen(void) const
{
	return (_fileStream.is_open());
}

void	FileOutput::CloseFile(void)
{
	_fileStream.close();
}

void	FileOutput::WriteOnFile(const std::string string)
{
	_fileStream << string;
}
