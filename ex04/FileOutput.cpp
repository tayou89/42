#include "FileOutput.hpp"

FileOutput::FileOutput(void)
	: _fileName("")
{
}

void	FileOutput::SetFileName(const std::string fileName)
{
	this->_fileName = fileName;
}

void	FileOutput::SetFileStream(void)
{
	_fileStream.open(_fileName);
}

void	FileOutput::WriteLine(const std::string line)
{
	if (line != "")
		_fileStream << line << std::endl;
}

int	FileOutput::IsFileStreamSet(void) const
{
	return (_fileStream.is_open());
}
