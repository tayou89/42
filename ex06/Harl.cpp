#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
	: complainLevel(-1)	
{
	std::string string[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void		(Harl::*pointer[4])(void)
				= { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	int			complainCount = 4;
	int			i;

	for (i = 0; i < complainCount; i++)
	{
		this->complainName[i] = string[i];
		this->functionPTR[i] = pointer[i];
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." <<std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::setComplainLevel(std::string complainName)
{
	int	complainCount = 4;
	int	i;

	for (i = 0; i < complainCount; i++)
	{
		if (this->complainName[i] == complainName)
		{
			this->complainLevel = i;
			break;
		}
	}
}

void	Harl::printComplainTitle(int complainLevel)
{
	std::cout << "[ " << complainName[complainLevel] << " ]" << std::endl;
}

void	Harl::complain(int complainLevel)
{
	(this->*functionPTR[complainLevel])();
}

void	Harl::printFilteredComplain(void)
{
	switch (complainLevel)
	{
	case 0:
		printComplainTitle(0);
		complain(0);
		std::cout << std::endl;
		__attribute__((fallthrough));
		
	case 1:
		printComplainTitle(1);
		complain(1);
		std::cout << std::endl;
		__attribute__((fallthrough));

	case 2:
		printComplainTitle(2);
		complain(2);
		std::cout << std::endl;
		__attribute__((fallthrough));

	case 3:
		printComplainTitle(3);
		complain(3);
		std::cout << std::endl;
		break ;

	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
