#include "PresidentialPardonForm.hpp"
#include <iostream>	

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon", _signGrade, _executeGrade), _target("")
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &object)
	: AForm(object.getName(), object.getSignGrade(), object.getExecuteGrade()),
	  _target(object.getTarget())
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &object)
{
	if (this == &object)
		return (*this);
	_target = object.getTarget();
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("Presidential Pardon", _signGrade, _executeGrade), _target(target)
{
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