#include "Character.hpp"

Character::Character(void)
	: _name(""), _inventorySlotCount(4) 
{
	int	i;

	for (i = 0; i < _inventorySlotCount; i++)
		_inventory[i] = NULL;
}

Character::~Character(void)
{
	int	i;

	for (i = 0; i < _inventorySlotCount; i++)
		_deleteInventorySlot(i);
}

Character::Character(const Character &object)
	: _name(object.getName()), _inventorySlotCount(object._inventorySlotCount)
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
	for (i = 0; i < _inventorySlotCount; i++)
	{
		_deleteInventorySlot(i);
		if (object._inventory[i] != NULL)
			this->_inventory[i] = object._inventory[i]->clone();
	}	
	return (*this);
}

Character::Character(const std::string name)
	: _name(name), _inventorySlotCount(4)
{
	int	i;

	for (i = 0; i < _inventorySlotCount; i++)
		_inventory[i] = NULL;
}

std::string const	&Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)	
{
	int	i;

	for (i = 0; i < _inventorySlotCount; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	_inventory[idx]->use(target);
}

void	Character::_deleteInventorySlot(int idx)
{
	if (this->_inventory[idx] != NULL)
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}
