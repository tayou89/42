#include "WordChange.hpp"

WordChange::WordChange(void)
	: _targetWord(""), _newWord("")
{
}

void	WordChange::SetTargetWord(const std::string targetWord)
{
	this->_targetWord = targetWord;
}

void	WordChange::SetNewWord(const std::string newWord)
{
	this->_newWord = newWord;
}

int	WordChange::IsTargetWordExist(std::string string) const
{

}
