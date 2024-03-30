#ifndef WORD_CHANGE_HPP
# define WORD_CHANGE_HPP

# include <string>
# include "Error.hpp"

class	WordChange
{
	public:
		WordChange(void);
		void		SetTargetWord(const std::string targetWord);
		void		SetNewWord(const std::string newWord);
		void		SetTargetString(const std::string targetString);
		std::string	ReplaceWithNewWord(void);

	private:
		int			_IsTargetWordExist(void) const;
		void		_GetTargetIndex(void);
		void		_EraseTargetWord(void);
		void		_InsertNewWord(void);
		void		_ResetSearchIndex(void);
		void		_InitIndex(void);

		std::string	_targetString;
		std::string	_targetWord;
		std::string	_newWord;
		int			_targetIndex;
		int			_searchIndex;
		Error		_error;
};

#endif
