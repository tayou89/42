#include "WordReplace.hpp"

WordReplace::WordReplace(void)
	: _targetIndex(-1), _searchIndex(0)
{
}

void	WordReplace::SetTargetWord(const std::string targetWord)
{
	if (targetWord == "")
		_error.HandleTargetWordError(targetWord);
	this->_targetWord = targetWord;
}

void	WordReplace::SetNewWord(const std::string newWord)
{
	this->_newWord = newWord;
}

void	WordReplace::SetTargetString(const std::string targetString)
{
	this->_targetString = targetString;
}

std::string	WordReplace::ReplaceWithNewWord(void)
{
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
