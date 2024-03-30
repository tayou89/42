#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::string				target("Home");				
	Bureaucrat				executor1("Tom", 1);		std::cout << '\n';													
	Bureaucrat				executor2("Bread", 150);	std::cout << '\n';					
	Bureaucrat				executor3("Lilly", 50);		std::cout << '\n';										
	ShrubberyCreationForm	shrubberyForm(target);		std::cout << '\n';					
	RobotomyRequestForm		robotForm(target);			std::cout << '\n';					
	PresidentialPardonForm	pardonForm(target);			std::cout << '\n';					

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