#ifndef FILE_INPUT_HPP
# define FILE_INPUT_HPP

# include <string>
# include <fstream>

class	FileInput
{
	public:
		FileInput(void);
		~FileInput(void);

		void		SetFilePath(const std::string filePath);
		std::string	GetFilePath(void) const;
		void		OpenFile(void);
		void		CloseFile(void);
		std::string	ReadFile(void);
		int			IsFileOpen(void) const;
		int			IsEndOfFile(void) const;

	private:
		std::string		_filePath;
		std::ifstream	_fileStream;
};

#endif
