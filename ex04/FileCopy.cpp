#include "FileCopy.hpp"
#include <iostream>

void	FileCopy::SetFileInput(const std::string filePath)
{
	_fileInput.SetFilePath(filePath);
	_fileInput.SetFileStream();
}

void	FileCopy::SetFileOutput(const std::string filePath)
{
	_fileOutput.SetFilePath(filePath);
	_fileOutput.SetFileStream();
}

void	FileCopy::SetWordChange(std::string targetWord, std::string newWord)
{
	_wordChange.SetTargetWord(targetWord);
	_wordChange.SetNewWord(newWord);
}

void	FileCopy::_GetLineFromInputFile(void)
{
	_fileLine = _fileInput.ReadLine();
}

void	FileCopy::_ChangeFileLineWithNewWord(void)
{
	_wordChange.SetTargetString(_fileLine);
	_fileLine = _wordChange.ReplaceWithNewWord();
}

void	FileCopy::_InsertLineToOutputFile(void)
{
	_fileOutput.WriteLine(_fileLine);
}

void	FileCopy::CopyFileWithWordChange(void)
{
	while (_fileInput.IsEndOfFile() == false)
	{
		_GetLineFromInputFile();
		_ChangeFileLineWithNewWord();
		_InsertLineToOutputFile();
	}
}
