#include "PresidentialPardonForm.hpp"
#include <iostream>	

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm(25, 5), _target("")
{
	std::cout << "PresidentialPardonForm default constructor is called, "
	          << "having a target " << _target << ".\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm having a target " << _target
	          << " destructor is called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &object)
	: AForm(object.getName(), object.getSignGrade(), object.getExecuteGrade()),
	  _target(object.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor is called, "
	          << "having a target " << _target << ".\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &object)
{
	if (this == &object)
		return (*this);
	AForm::operator=(object);
	_target = object.getTarget();
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm(25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor is called, "
	          << "having a target " << _target << ".\n"; 
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkExecuteRequirements(executor);
	std::cout << "Target " << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}