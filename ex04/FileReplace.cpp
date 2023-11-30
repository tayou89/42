#include "FileReplace.hpp"
#include <iostream>

void	FileReplace::OpenInputFile(const std::string filePath)
{
	_fileInput.SetFilePath(filePath);
	_fileInput.OpenFile();
}

void	FileReplace::OpenOutputFile(const std::string filePath)
{
	_fileOutput.SetFilePath(filePath);
	_fileOutput.OpenFile();
}

void	FileReplace::SetReplacingWord(const std::string targetWord, const std::string newWord)
{
	_wordReplace.SetTargetWord(targetWord);
	_wordReplace.SetNewWord(newWord);
}

void	FileReplace::_GetReadStringFromInputFile(void)
{
	_readString = _fileInput.ReadFile();
}

void	FileReplace::_ReplaceReadStringWord(void)
{
	_wordReplace.SetTargetString(_readString);
	_readString = _wordReplace.ReplaceWithNewWord();
}

void	FileReplace::_WriteReadStringOnOutputFile(void)
{
	_fileOutput.WriteOnFile(_readString);
}

void	FileReplace::_CloseFiles(void)
{
	_fileInput.CloseFile();
	_fileOutput.CloseFile();
}

void	FileReplace::MakeReplacedFile(void)
{
	while (_fileInput.IsEndOfFile() == false)
	{
		_GetReadStringFromInputFile();
		_ReplaceReadStringWord();
		_WriteReadStringOnOutputFile();
	}
	_CloseFiles();
}
