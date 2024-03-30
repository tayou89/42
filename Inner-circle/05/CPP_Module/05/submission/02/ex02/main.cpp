#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::string				target("Home");				
	Bureaucrat				executor1("Tom", 1);
	Bureaucrat				executor2("Bread", 150);
	Bureaucrat				executor3("Lilly", 50);
	ShrubberyCreationForm	shrubberyForm(target);
	RobotomyRequestForm		robotForm(target);
	PresidentialPardonForm	pardonForm(target);

	executor1.signForm(shrubberyForm);
	executor1.signForm(robotForm);
	executor1.signForm(pardonForm);
	std::cout << '\n';

	executor1.executeForm(shrubberyForm);
	executor1.executeForm(robotForm);
	executor1.executeForm(pardonForm);
	std::cout << '\n';

	executor2.executeForm(shrubberyForm);
	executor2.executeForm(robotForm);
	executor2.executeForm(pardonForm);
	std::cout << '\n';

	executor3.executeForm(shrubberyForm);
	executor3.executeForm(robotForm);
	executor3.executeForm(pardonForm);
	std::cout << '\n';
	return (0);
}