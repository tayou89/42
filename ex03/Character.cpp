#include "Character.hpp"
#include <iostream>

Character::Character(void)
	: _inventory(), _name("") 
{
}

Character::~Character(void)
{
	int	i;

	for (i = 0; i < _inventorySlotCount; i++)
		_deleteInventorySlot(i);
}

Character::Character(const Character &object)
	:	ICharacter(), _inventory(), _name(object.getName())
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
	: _name(name) 
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

	if (m == NULL)
	{
		std::cout << "Invalid materia: " << _name << " can't equip.\n";
		return ;
	}
	for (i = 0; i < _inventorySlotCount; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << _name << ": inventory[" << i << "] is equipped.\n";
			return ;
		}
	}
	std::cout << _name << " can't equip materia: inventory is alrealy full.\n";
	delete m;
	m = NULL;
}

void	Character::unequip(int idx)
{
	if (_isValidInventoryIndex(idx) == true)
	{
		_inventory[idx] = NULL;
		std::cout << _name << ": inventory[" << idx << "] is unequipped.\n";
	}
	else
		std::cout << _name << ": inventory[" << idx << "] is invalid to equipped.\n";
}

void	Character::use(int idx, ICharacter &target)
{
	if (_isValidInventoryIndex(idx) == false || _inventory[idx] == NULL)
	{
		std::cout << _name << ": can't use materia: "; 
		if (_isValidInventoryIndex(idx) == false)
			std::cout << "Inventory[" << idx << "] is invalid." << std::endl;
		else
			std::cout << "Inventory[" << idx << "] is not equipped." << std::endl; 
	}
	else
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

bool	Character::_isValidInventoryIndex(int idx)
{
	if (idx >= 0 && idx < _inventorySlotCount)
		return (true);
	else
		return (false);
}