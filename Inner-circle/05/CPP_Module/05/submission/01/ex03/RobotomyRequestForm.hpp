#ifndef ROBO_TO_MY_REQUEST_FORM_HPP
# define ROBO_TO_MY_REQUEST_FORM_HPP

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &object);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &object);

		RobotomyRequestForm(const std::string target);
		virtual void	execute(Bureaucrat const &executor) const;
		std::string		getTarget(void) const;

	private:
		std::string	_target;
};

#endif