#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
    : _name(""), _grade(_lowestGrade)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &object)
    : _name(object.getName()), _grade(object.getGrade())
{
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &object)
{
    std::string &nameREF = const_cast<std::string &>(this->_name);

    if (this != &object)
    {
        nameREF = object.getName();
        this->_grade = object.getGrade();
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
    : _name(name), _grade(_lowestGrade)
{
	if (grade < _highestGrade)
		throw Bureaucrat::GradeTooHighException();
	if (grade > _lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

std::string Bureaucrat::getName(void) const
{
    return (_name);    
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void    Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < _highestGrade)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void    Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > _lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);	
		std::cout << *this << " signed " << form << ".\n";
	}
	catch(const std::exception &exception)
	{
		std::cerr << *this << " couldn't sign " << form << '\n'
				<< "becuase " << exception.what() << ".\n";
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << ".\n";
	}
	catch (const std::exception& exception)
	{
		std::cerr << *this << " couldn't execute " << form << '\n'
		          << "because " << exception.what() << ".\n"; 
	}
}

const char  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high");
}

const char  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low");
}

std::ostream    &operator<<(std::ostream &stream, const Bureaucrat &object)
{
    stream << object.getName() << ", bureaucrat grade " << object.getGrade();
	return (stream);
}