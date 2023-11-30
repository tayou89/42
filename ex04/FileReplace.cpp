#include "FileReplace.hpp"

FileReplace::FileReplace(int argc, const char *argv[])
	: _readString("")
{
	std::string	replaceExtension = ".replace";

	if (argc < 3)
		_error.HandleArgumentCountError();
	_fileInput.SetFilePath(argv[0]);
	_fileOutput.SetFilePath(argv[0] + replaceExtension);
	_wordReplace.SetTargetWord(argv[1]);
	if (_wordReplace.GetTargetWord() == "")
		_error.HandleTargetWordError("");
	_wordReplace.SetNewWord(argv[2]);
}

void	FileReplace::_OpenInputFile(void)
{
	_fileInput.OpenFile();
	if (_fileInput.IsFileOpen() == false)
		_error.HandleFileOpenError(_fileInput.GetFilePath());
}

void	FileReplace::_OpenOutputFile(void)
{
	_fileOutput.OpenFile();
	if (_fileOutput.IsFileOpen() == false)
	{
		_CloseInputFile();
		_error.HandleFileOpenError(_fileOutput.GetFilePath());
	}
}
void	FileReplace::_GetReadStringFromInputFile(void)
{
	_readString = _fileInput.ReadFile();
}

void	FileReplace::_ReplaceReadStringWord(void)
{
	_readString = _wordReplace.ReplaceWithNewWord(_readString);
}

void	FileReplace::_WriteReadStringOnOutputFile(void)
{
	_fileOutput.WriteOnFile(_readString);
}

void	FileReplace::_CloseInputFile(void)
{
	_fileInput.CloseFile();
}

void	FileReplace::_CloseOutputFile(void)
{
	_fileOutput.CloseFile();
}

void	FileReplace::MakeReplacedFile(void)
{
	_OpenInputFile();
	_OpenOutputFile();
	while (_fileInput.IsEndOfFile() == false)
	{
		_GetReadStringFromInputFile();
		_ReplaceReadStringWord();
		_WriteReadStringOnOutputFile();
	}
	_CloseInputFile();
	_CloseOutputFile();
}
