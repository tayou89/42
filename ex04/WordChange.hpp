#ifndef WORD_CHANGE_HPP
# define WORD_CHANGE_HPP

class	WordChange
{
	public:
		void		SetTargetWord(const std::string targetWord);
		void		SetNewWord(const std::string newWord);
		int			IsTargetWordExist(std::string string) const;
		std::string	ReplaceWithNewWord(std::string string);

	private:
		std::string	_targetWord;
		std::string	_newWord;
};

#endif
