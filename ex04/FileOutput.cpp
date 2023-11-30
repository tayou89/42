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

void	FileOutput::OpenFile(void)
{
	_fileStream.open(_filePath.c_str());
	if (_fileStream.is_open() == false)
		_error.HandleFileOpenError(_filePath);
}

void	FileOutput::CloseFile(void)
{
	_fileStream.close();
}

void	FileOutput::WriteOnFile(const std::string string)
{
	_fileStream << string;
}
