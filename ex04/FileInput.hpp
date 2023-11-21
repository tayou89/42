#ifndef FILE_INPUT_HPP
# define FILE_INPUT_HPP

# include <string>
# include <fstream>

class	FileInput
{
	public:
		void		FileInput(void);
		void		SetFilePath(const std::string	filePath);
		void		SetFileStream(void);
		std::string	ReadLine(void);
		int			IsFileStreamSet(void) const;
		int			IsEndOfFile(void) const;

	private:
		std::string		_filePath;
		std::ifstream	_fileStream;
};

#endif
