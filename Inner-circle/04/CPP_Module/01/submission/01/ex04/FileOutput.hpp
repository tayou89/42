#ifndef FILE_OUTPUT_HPP
# define FILE_OUTPUT_HPP

# include <string>
# include <fstream>
# include "Error.hpp"

class	FileOutput
{
	public:
		FileOutput(void);
		std::string	GetFilePath(void) const;
		void	SetFilePath(const std::string filePath);
		void	SetFileStream(void);	
		void	WriteLine(const std::string line);

	private:
		std::string		_filePath;
		std::ofstream	_fileStream;
		Error			_error;
};

#endif
