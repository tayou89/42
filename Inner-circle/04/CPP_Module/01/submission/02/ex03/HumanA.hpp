#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(const std::string name, Weapon &club);
		void	attack(void) const;

	private:
		std::string	name;
		Weapon		&weaponREF;
};

#endif
