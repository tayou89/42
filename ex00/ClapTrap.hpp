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

		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
	
		void			setAttackDamage(unsigned int amount);
		int				getAttackDamage(void) const;

	private:
		std::string		getName(void) const;
		int				getHitPoints(void) const;
		int				getEnergyPoints(void) const;

		std::string		name;
		int				hitPoints;
		int				energyPoints;
		unsigned int	attackDamage;

};

#endif
