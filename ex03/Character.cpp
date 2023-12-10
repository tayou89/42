#include "Character.hpp"

Character::Character(void)
	: _name(""), _inventory( NULL, NULL, NULL, NULL)
{
}

Character::~Character(void)
{
	int	i;

	for (i = 0; i < _inventorySlotCount; i++)
		_deleteInventorySlot(i);
}

Character::Character(const Character &object)
{
	int	i;

	for (i = 0; i < _inventorySlotCount; i++)
	{
		if (object._inventory[i] != NULL)
			_inventory[i] = object._inventory[i]->clone();
	}
}

Character	&Character::operator=(const Character &object)
{
	int	i;

	if (this == &object)
		return (*this);
	for (i = 0; i < _inventroySlotCount; i++)
	{
		_deleteInventorySlot(i);
		if (object._inventory[i] != NULL)
			this->_inventory[i] = object._inventory[i]->clone();
	}	
}

Character::Character(const std::string name)
	: name(name), _inventory( NULL, NULL, NULL, NULL )
{
}

std::string const	&Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)	
{

}
void	Character::_deleteInventorySlot(int idx)
{
	if (this->_inventory[idx] != NULL)
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}