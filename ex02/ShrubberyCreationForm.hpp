#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &object);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &object);

		ShrubberyCreationForm(const std::string target);
		virtual	void	execute(Bureaucrat const &executor) const;
		std::string		getTarget(void) const;
	
	private:
		void	_writeASCIITree(void) const;

		std::string	_target;
};

#endif