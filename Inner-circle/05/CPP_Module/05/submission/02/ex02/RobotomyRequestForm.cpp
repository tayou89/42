#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request", _signGrade, _executeGrade), _target("")
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &object)
	: AForm(object.getName(), object.getSignGrade(), object.getExecuteGrade()),
	  _target(object.getTarget())
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &object)
{
	if (this == &object)
		return (*this);
	_target = object.getTarget();
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("Robotomy Request", _signGrade, _executeGrade), _target(target)
{
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