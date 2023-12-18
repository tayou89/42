#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request", 72, 45), _target("")
{
	std::cout << "RobotomyRequestForm defulat constructor is called, "
	          << "having a target " << _target << ".\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm having a target " << _target
	          << " destructor is called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &object)
	: AForm(object.getName(), object.getSignGrade(), object.getExecuteGrade()),
	  _target(object.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor is called, "
	          << "having a target " << _target << ".\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &object)
{
	if (this == &object)
		return (*this);
	AForm::operator=(object);
	_target = object.getTarget();
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("Robotomy Request", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor is called, "
	          << "having a target " << _target << ".\n";
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::time_t	currentTime = std::time(NULL);

	checkExecuteRequirements(executor);
	std::cout << "ZzzzzzzzzzzZzzzzzzzzzzzzzZZZZZZZZZZZzzzzzz....\n";
	if (currentTime % 2 == 0)
		std::cout << "Target " << _target << " has been sucessfully robotomized.\n";
	else
		std::cout << "Robotomize target " << _target << " has been failed.\n";
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}