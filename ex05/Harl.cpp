#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
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

void	Harl::complain(std::string level)
{
	std::string	complainLevel[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void		(Harl::*functionPTR[4])(void) 
					= { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	int			complainCount = 4;
	int			i;

	for (i = 0; i < complainCount; i++)
	{
		if (complainLevel[i] == level)
			(this->*functionPTR[i])();
	}
}
