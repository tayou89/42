#ifndef CHARACTER_HPP
# define CHARACTER_HPP 

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(void);
		virtual	~Character(void);
		Character(const Character &object);
		Character	&operator=(const Character &object);

		Character(const std::string name);
		virtual std::string const	&getName(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);

	private:
		void				_deleteInventorySlot(int idx);
		bool				_isValidInventoryIndex(int idx);

		static const int	_inventorySlotCount = 4;
		AMateria			*_inventory[_inventorySlotCount];
		std::string			_name;
};

#endif