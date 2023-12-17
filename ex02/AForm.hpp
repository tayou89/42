#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <string>
# include <exception>
class	Bureaucrat;

class	AForm
{
	public:
		AForm(void);
		virtual ~AForm(void);
		AForm(const AForm &object);
		AForm	&operator=(const AForm &object);

		AForm(const std::string name);
		AForm(const std::string name, const int signGrade);
		AForm(const std::string name, const int signGrade, const int executeGrade);
		AForm(const int signGrade, const int executeGrade);

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;
		void			beSigned(const Bureaucrat &bureaucrat);
		virtual	void	execute(Bureaucrat const &executor) const = 0;

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};	
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	private:
		void				_setGrade(int &gradeToset, const int settingGrade);

		static const int	_highestGrade = 1;
		static const int	_lowestGrade = 150;
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream	&operator<<(std::ostream &stream, const AForm &object); 

#endif