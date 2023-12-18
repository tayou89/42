#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &object);

		PresidentialPardonForm(const std::string target);
		virtual void	execute(Bureaucrat const &executor) const;
		std::string		getTarget(void) const;
	
	private:
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &object);

		static const int	_signGrade = 25;
		static const int	_executeGrade = 5;
		std::string			_target;
};

#endif