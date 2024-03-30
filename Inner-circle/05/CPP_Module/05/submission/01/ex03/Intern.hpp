#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &object);
		Intern	&operator=(const Intern &object);

		AForm	*makeForm(const std::string &formName, const std::string &formTarget);
};

#endif