#include "Intern.hpp"
#include <iostream>

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Intern::Intern(const Intern &object)
{
	std::cout << "Intern copy constructor is called.\n";
	*this = object;
}

Intern	&Intern::operator=(const Intern &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	AForm		*formPTR = NULL;
	const int	formNameCount = 3;
	std::string	formNameList[formNameCount] = { ShrubberyCreationForm().getName(), 
												RobotomyRequestForm().getName(), 
												PresidentialPardonForm().getName() };
	int			i;

	for (i = 0; (i < formNameCount) && (formName != formNameList[i]); i++);
	switch (i)
	{
		case 0:
			formPTR = new ShrubberyCreationForm(formTarget);
			break ;
		case 1:
			formPTR = new RobotomyRequestForm(formTarget);
			break ;
		case 2:
			formPTR = new PresidentialPardonForm(formTarget);
			break ;
		default:
			std::cout << "Intern failed to create " << formName << '\n';
			return (formPTR);
	}
	std::cout << "Intern creates " << *formPTR << '\n';
	return (formPTR);
}