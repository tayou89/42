#ifndef FILE_OUTPUT_HPP
# define FILE_OUTPUT_HPP

# include <string>
# include <fstream>

class	FileOutput
{
	public:
		FileOutput(void);
		void	SetFileName(const std::string fileName);
		void	SetFileStream(void);
		void	WriteLine(const std::string line);
		int		IsFileStreamSet(void) const;

	private:
		std::string		_fileName;
		std::ofstream	_fileStream;
};

#endif
