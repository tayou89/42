#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(void)
	: 	_name(""), _isSigned(false), 
		_signGrade(_highestGrade), _executeGrade(_highestGrade)
{
}
		
AForm::~AForm(void)
{
}

AForm::AForm(const AForm &object)
	:	_name(object.getName()), _isSigned(object.getIsSigned()),
		_signGrade(object.getSignGrade()), _executeGrade(object.getExecuteGrade())
{
}

AForm	&AForm::operator=(const AForm &object)
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

AForm::AForm(const std::string name, const int signGrade, const int executeGrade)
	: _name(name), _isSigned(false),
	  _signGrade(_highestGrade), _executeGrade(_highestGrade)
{
	if (signGrade < _highestGrade || executeGrade < _highestGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > _lowestGrade || executeGrade > _lowestGrade)
		throw AForm::GradeTooLowException();
	int	&signGradeREF = const_cast<int &>(this->_signGrade);
	int	&executeGradeREF = const_cast<int &>(this->_executeGrade);

	signGradeREF = signGrade;
	executeGradeREF = executeGrade;	
}

AForm::AForm(const int signGrade, const int executeGrade)
	: _name(""), _isSigned(false), 
	  _signGrade(_highestGrade), _executeGrade(_highestGrade)
{
	if (signGrade < _highestGrade || executeGrade < _highestGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > _lowestGrade || executeGrade > _lowestGrade)
		throw AForm::GradeTooLowException();
	int	&signGradeREF = const_cast<int &>(this->_signGrade);
	int	&executeGradeREF = const_cast<int &>(this->_executeGrade);

	signGradeREF = signGrade;
	executeGradeREF = executeGrade;	
}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getExecuteGrade(void) const
{
	return (_executeGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();	
	_isSigned = true;	
}

void	AForm::checkExecuteRequirements(const Bureaucrat &executor) const
{
	if (_isSigned == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

const char	*AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed");
}

std::ostream	&operator<<(std::ostream &stream, const AForm &object)
{
	stream << "AForm name: " << object.getName() << ", ";
	if (object.getIsSigned() == true)
		stream << "IsSigned: TRUE, ";
	else
		stream << "IsSigned: FALSE, ";
	stream << "Sign grade: " << object.getSignGrade() << ", ";
	stream << "Execute grade: " << object.getExecuteGrade();
	return (stream);
}