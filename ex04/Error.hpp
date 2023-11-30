#ifndef ERROR_HPP
# define ERROR_HPP

# include <string>

class	Error
{
	public:
		Error(void);
		void	HandleArgumentCountError(void) const;
		void	HandleFilePathError(std::string wrongFilePath) const;
		void	HandleFileOpenError(std::string filePath) const;
		void	HandleTargetWordError(std::string wrongTargetWord) const;

	private:
		void	_PrintErrorMessage(std::string errorMessage, std::string errorSource) const;

		std::string	_errorPrompt;
};

#endif
