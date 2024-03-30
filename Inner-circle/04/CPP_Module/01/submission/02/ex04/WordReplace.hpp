#ifndef WORD_REPLACE_HPP
# define WORD_REPLACE_HPP

# include <string>

class	WordReplace
{
	public:
		WordReplace(void);
		void		SetTargetWord(const std::string targetWord);
		void		SetNewWord(const std::string newWord);
		std::string	GetTargetWord(void) const;
		std::string	ReplaceWithNewWord(const std::string string);

	private:
		void		_SetTargetString(const std::string string);
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
};

#endif
