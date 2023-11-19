#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(const std::string name);
		void	attack(void) const;
		void	setWeapon(Weapon &weaponREF);

	private:
		std::string	name;
		Weapon		*weaponPTR;
};

#endif
