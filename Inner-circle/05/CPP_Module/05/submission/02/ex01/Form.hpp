#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
class	Bureaucrat;

class	Form
{
	public:
		Form(void);
		~Form(void);
		Form(const Form &object);

		Form(const std::string name, const int signGrade, const int executeGrade);
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		void		beSigned(const Bureaucrat &bureaucrat);

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
		Form	&operator=(const Form &object);

		static const int	_highestGrade = 1;
		static const int	_lowestGrade = 150;
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream	&operator<<(std::ostream &stream, const Form &object); 

#endif