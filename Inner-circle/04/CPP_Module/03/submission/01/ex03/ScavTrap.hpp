#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		~ScavTrap(void);
		ScavTrap(const ScavTrap &object);
		ScavTrap	&operator=(const ScavTrap &object);
		
		ScavTrap(const std::string name);
		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif
