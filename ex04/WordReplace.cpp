#include "WordReplace.hpp"

WordReplace::WordReplace(void)
	: _targetIndex(-1), _searchIndex(0)
{
}

void	WordReplace::SetTargetWord(const std::string targetWord)
{
	this->_targetWord = targetWord;
}

std::string	WordReplace::GetTargetWord(void) const
{
	return (_targetWord);
}

void	WordReplace::SetNewWord(const std::string newWord)
{
	this->_newWord = newWord;
}

void	WordReplace::_SetTargetString(const std::string string)
{
	this->_targetString = string;
}

std::string	WordReplace::ReplaceWithNewWord(const std::string string)
{
	_SetTargetString(string);
	while (_IsTargetWordExist() == true)
	{
		_GetTargetIndex();
		_EraseTargetWord();
		_InsertNewWord();
		_ResetSearchIndex();
	}
	_InitIndex();
	return (_targetString);
}

int	WordReplace::_IsTargetWordExist(void) const
{
	if (_targetString.find(_targetWord, _searchIndex) == std::string::npos)
		return (false);
	else
		return (true);
}

void	WordReplace::_GetTargetIndex(void)
{
	_targetIndex = _targetString.find(_targetWord, _searchIndex);
}

void	WordReplace::_EraseTargetWord(void)
{
	_targetString.erase(_targetIndex, _targetWord.length());
}

void	WordReplace::_InsertNewWord(void)
{
	_targetString.insert(_targetIndex, _newWord);
}

void	WordReplace::_ResetSearchIndex(void)
{
	_searchIndex = _targetIndex + _newWord.length();
}

void	WordReplace::_InitIndex(void)
{
	_targetIndex = -1;
	_searchIndex = 0;
}
