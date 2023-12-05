#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap
{
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &object);
		ClapTrap	&operator=(const ClapTrap &object);

		ClapTrap(std::string name);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
		int		getAttackDamage(void) const;
		int		getHitPoints(void) const;

	protected:
		std::string		name;
		int				hitPoints;
		int				energyPoints;
		unsigned int	attackDamage;

};

#endif
