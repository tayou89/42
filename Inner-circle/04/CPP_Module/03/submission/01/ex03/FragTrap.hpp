#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap(void);
		FragTrap(const FragTrap &object);
		FragTrap	&operator=(const FragTrap &object);

		FragTrap(const std::string name);
		void	highFivesGuys(void);
};

#endif
