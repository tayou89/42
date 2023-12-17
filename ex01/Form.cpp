#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(void)
	: 	_name(""), _isSigned(false), 
		_signGrade(_lowestGrade), _executeGrade(_lowestGrade)
{
	std::cout << "Form default constructor is called.\n";
	std::cout << *this << '\n';
}

Form::~Form(void)
{
	std::cout << "Form " << _name << " destructor is called.\n";
}

Form::Form(const Form &object)
	:	_name(object.getName()), _isSigned(object.getIsSigned()),
		_signGrade(object.getSignGrade()), _executeGrade(object.getExecuteGrade())
{
	std::cout << "Form " << _name << " copy constructor is called.\n";
	std::cout << *this << '\n';
}

Form	&Form::operator=(const Form &object)
{
	if (this == &object)
		return (*this);
	std::string	&nameREF = const_cast<std::string &>(this->_name);
	int			&signGradeREF = const_cast<int &>(this->_signGrade);
	int			&executeGradeREF = const_cast<int &>(this->_executeGrade);

	nameREF = object.getName();
	signGradeREF = object.getSignGrade();
	executeGradeREF = object.getExecuteGrade();
	return (*this);
}

Form::Form(const std::string name)
	: _name(name), _signGrade(_lowestGrade), _executeGrade(_lowestGrade)
{
	std::cout << "Form " << _name << " constructor is called.\n";
	std::cout << *this << '\n';
}

Form::Form(const std::string name, const int signGrade)
	: _name(name), _signGrade(_lowestGrade), _executeGrade(_lowestGrade)
{
	std::cout <<"Form " << _name << " constructor is called.\n";
	_setGrade(const_cast<int &>(this->_signGrade), signGrade);
}

Form::Form(const std::string name, const int signGrade, const int executeGrade)
	: _name(name), _signGrade(_lowestGrade), _executeGrade(_lowestGrade)
{
	std::cout << "Form " << _name << " constructor is called.\n";
	_setGrade(const_cast<int &>(this->_signGrade), signGrade);
	_setGrade(const_cast<int &>(this->_executeGrade), executeGrade);
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

void	Form::_setGrade(int &gradeToSet, const int settingGrade)
{
	try
	{
		std::cout << "Form: Trying to set grade " << settingGrade << '\n';
		if (settingGrade < _highestGrade)
			throw Form::GradeTooHighException();
		if (settingGrade > _lowestGrade)
			throw Form::GradeTooLowException();
		gradeToSet = settingGrade;
		std::cout << "Success to set grade." << '\n';
		std::cout << *this << '\n';
	}
	catch (const Form::GradeTooHighException &exception)
	{
		std::cerr << "Fail to set grade: " << exception.what() << ".\n";
		gradeToSet = _highestGrade;
		std::cerr << *this << ".\n"; 
	}
	catch (const Form::GradeTooLowException &exception)
	{
		std::cerr << "Failed to set grade: " << exception.what() << ".\n";
		gradeToSet = _lowestGrade;
		std::cerr << *this << ".\n";
	}
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