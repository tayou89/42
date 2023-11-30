#ifndef FILE_REPLACE_HPP
# define FILE_REPLACE_HPP

# include "FileInput.hpp"
# include "FileOutput.hpp"
# include "WordReplace.hpp"

class	FileReplace
{
	public:
		void	OpenInputFile(const std::string filePath);
		void	OpenOutputFile(const std::string filePath);
		void	SetReplacingWord(const std::string targetWord, const std::string newWord);
		void	MakeReplacedFile(void);

	private:
		void	_GetReadStringFromInputFile(void);
		void	_ReplaceReadStringWord(void);
		void	_WriteReadStringOnOutputFile(void);
		void	_CloseFiles(void);

		std::string	_readString;
		FileInput	_fileInput;
		FileOutput	_fileOutput;
		WordReplace	_wordReplace;
};

#endif
