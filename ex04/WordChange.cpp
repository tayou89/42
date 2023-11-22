#include "WordChange.hpp"

WordChange::WordChange(void)
	: _targetIndex(-1), _searchIndex(0)
{
}

void	WordChange::SetTargetWord(const std::string targetWord)
{
	if (targetWord == "")
		_error.HandleTargetWordError(targetWord);
	this->_targetWord = targetWord;
}

void	WordChange::SetNewWord(const std::string newWord)
{
	this->_newWord = newWord;
}

void	WordChange::SetTargetString(const std::string targetString)
{
	this->_targetString = targetString;
}

std::string	WordChange::ReplaceWithNewWord(void)
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

int	WordChange::_IsTargetWordExist(void) const
{
	if (_targetString.find(_targetWord, _searchIndex) == std::string::npos)
		return (false);
	else
		return (true);
}

void	WordChange::_GetTargetIndex(void)
{
	_targetIndex = _targetString.find(_targetWord, _searchIndex);
}

void	WordChange::_EraseTargetWord(void)
{
	_targetString.erase(_targetIndex, _targetWord.length());
}

void	WordChange::_InsertNewWord(void)
{
	_targetString.insert(_targetIndex, _newWord);
}

void	WordChange::_ResetSearchIndex(void)
{
	_searchIndex = _targetIndex + _newWord.length();
}

void	WordChange::_InitIndex(void)
{
	_targetIndex = -1;
	_searchIndex = 0;
}
