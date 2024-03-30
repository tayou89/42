#ifndef FILE_OUTPUT_HPP
# define FILE_OUTPUT_HPP

# include <string>
# include <fstream>

class	FileOutput
{
	public:
		FileOutput(void);
		~FileOutput(void);

		void		SetFilePath(const std::string filePath);
		std::string	GetFilePath(void) const;
		void		OpenFile(void);	
		void		CloseFile(void);	
		void		WriteOnFile(const std::string line);
		int			IsFileOpen(void) const;

	private:
		std::string		_filePath;
		std::ofstream	_fileStream;
};

#endif
