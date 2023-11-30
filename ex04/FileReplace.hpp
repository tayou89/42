#ifndef FILE_REPLACE_HPP
# define FILE_REPLACE_HPP

# include "FileInput.hpp"
# include "FileOutput.hpp"
# include "WordReplace.hpp"
# include "Error.hpp"

class	FileReplace
{
	public:
		FileReplace(int argc, const char *argv[]);
		void	MakeReplacedFile(void);

	private:
		void	_OpenInputFile();
		void	_OpenOutputFile();
		void	_CloseInputFile(void);
		void	_CloseOutputFile(void);
		void	_GetReadStringFromInputFile(void);
		void	_ReplaceReadStringWord(void);
		void	_WriteReadStringOnOutputFile(void);

		FileInput	_fileInput;
		FileOutput	_fileOutput;
		WordReplace	_wordReplace;
		Error		_error;
		std::string	_readString;
};

#endif
