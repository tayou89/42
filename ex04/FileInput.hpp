#ifndef FILE_INPUT_HPP
# define FILE_INPUT_HPP

# include <string>
# include <fstream>
# include "Error.hpp"

class	FileInput
{
	public:
		FileInput(void);
		~FileInput(void);

		void		SetFilePath(const std::string filePath);
		void		OpenFile(void);
		void		CloseFile(void);
		std::string	ReadFile(void);
		int			IsEndOfFile(void) const;

	private:
		std::string		_filePath;
		std::ifstream	_fileStream;
		Error			_error;
};

#endif
