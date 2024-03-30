#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(void)
	: 	_name(""), _isSigned(false), 
		_signGrade(_highestGrade), _executeGrade(_highestGrade)
{
}

Form::~Form(void)
{
}

Form::Form(const Form &object)
	:	_name(object.getName()), _isSigned(false),
		_signGrade(object.getSignGrade()), _executeGrade(object.getExecuteGrade())
{
}

Form	&Form::operator=(const Form &object)
{
	if (this == &object)
		return (*this);
	std::string	&nameREF = const_cast<std::string &>(this->_name);
	int			&signGradeREF = const_cast<int &>(this->_signGrade);
	int			&executeGradeREF = const_cast<int &>(this->_executeGrade);

	_isSigned = object.getIsSigned();
	nameREF = object.getName();
	signGradeREF = object.getSignGrade();
	executeGradeREF = object.getExecuteGrade();
	return (*this);
}

Form::Form(const std::string name, const int signGrade, const int executeGrade)
	: _name(name), _isSigned(false),
	  _signGrade(_highestGrade), _executeGrade(_highestGrade)
{
	if (signGrade < _highestGrade || executeGrade < _highestGrade)
		throw Form::GradeTooHighException();
	if (signGrade > _lowestGrade || executeGrade > _lowestGrade)
		throw Form::GradeTooLowException();

	int	&signGradeREF = const_cast<int &>(this->_signGrade);
	int	&executeGradeREF = const_cast<int &>(this->_executeGrade);

	signGradeREF = signGrade;
	executeGradeREF = executeGrade;
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

int	Form::getSignGrade(void) const
{
	return (_signGrade);
}

int	Form::getExecuteGrade(void) const
{
	return (_executeGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();	
	_isSigned = true;	
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &stream, const Form &object)
{
	stream << "Form name: " << object.getName() << ", ";
	if (object.getIsSigned() == true)
		stream << "IsSigned: TRUE, ";
	else
		stream << "IsSigned: FALSE, ";
	stream << "Sign grade: " << object.getSignGrade() << ", ";
	stream << "Execute grade: " << object.getExecuteGrade();
	return (stream);
}