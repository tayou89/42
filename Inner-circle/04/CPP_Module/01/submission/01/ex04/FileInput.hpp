#ifndef FILE_INPUT_HPP
# define FILE_INPUT_HPP

# include <string>
# include <fstream>
# include "Error.hpp"

class	FileInput
{
	public:
		FileInput(void);
		std::string	GetFilePath(void) const;
		void		SetFilePath(const std::string filePath);
		void		SetFileStream(void);
		std::string	ReadLine(void);
		int			IsEndOfFile(void) const;

	private:
		void		_GetFileLineFromInput(void);
		void		_HandleFilePathError(std::string wrongFilePath) const;
		void		_HandleFileOpenError(void) const;

		std::string		_fileline;
		std::string		_filePath;
		std::ifstream	_fileStream;
		Error			_error;
};

#endif
