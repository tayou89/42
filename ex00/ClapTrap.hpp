#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap
{
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &object);
		ClapTrap	&operator=(const ClapTrap &object);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
	private:
		std::string		name;
		int				hitPoints;
		int				energyPoints;
		unsigned int	attackDamage;

};

#endif
