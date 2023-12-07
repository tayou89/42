#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class  DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(void);
        ~DiamondTrap(void);
        DiamondTrap(const DiamondTrap &object);
        DiamondTrap &operator=(const DiamondTrap &object);
		
		DiamondTrap(std::string name);
		void	whoAmI(void) const;
        
    private:
        std::string name;
};

#endif
