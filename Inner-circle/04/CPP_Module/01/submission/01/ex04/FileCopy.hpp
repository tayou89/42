#ifndef FILE_COPY_HPP
# define FILE_COPY_HPP

# include "FileInput.hpp"
# include "FileOutput.hpp"
# include "WordChange.hpp"

# define	COPYFILE_EXTENSION	".replace"

class	FileCopy
{
	public:
		void	SetFileInput(const std::string filePath);
		void	SetFileOutput(const std::string filePath);
		void	SetWordChange(std::string targetWord, std::string newWord);
		void	CopyFileWithWordChange(void);

	private:
		void	_GetLineFromInputFile(void);
		void	_ChangeFileLineWithNewWord(void);
		void	_InsertLineToOutputFile(void);

		std::string	_fileLine;
		FileInput	_fileInput;
		FileOutput	_fileOutput;
		WordChange	_wordChange;
};

#endif
