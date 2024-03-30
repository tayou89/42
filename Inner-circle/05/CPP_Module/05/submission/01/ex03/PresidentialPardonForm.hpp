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
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &object);

		PresidentialPardonForm(const std::string target);
		virtual void	execute(Bureaucrat const &executor) const;
		std::string		getTarget(void) const;
	
	private:
		std::string	_target;
};

#endif