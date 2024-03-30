#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
	: _materia()
{
}

MateriaSource::~MateriaSource(void)
{
    int i;

    for (i = 0; i < _materiaMaxCount; i++)
        _deleteMateriaSource(i);
}

MateriaSource::MateriaSource(const MateriaSource &object)
	: IMateriaSource(), _materia()
{
	int	i;

	for (i = 0; i < _materiaMaxCount; i++)
	{
		if (object._materia[i] != NULL)
			_materia[i] = object._materia[i]->clone();
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &object)
{
	int	i;

	if (this == &object)
		return (*this);
	for (i = 0; i < _materiaMaxCount; i++)
	{
		_deleteMateriaSource(i);
		if (object._materia[i] != NULL)
			_materia[i] = object._materia[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *aMateriaPTR)
{
	int	i;
	
	if (aMateriaPTR == NULL)
	{
		std::cout << "Invalid materia: MateriSource can't learn.\n";
		return ;
	}
	for (i = 0; i < _materiaMaxCount; i++)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = aMateriaPTR;
			std::cout << "MateriaSource learned " << aMateriaPTR->getType() << std::endl;
			return ;
		}
	}
	std::cout << "LearnMateria failed. MateriaSource is already full.\n";
	delete aMateriaPTR;
}


AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i;

	for (i = 0; i < _materiaMaxCount; i++)
	{
		if (_materia[i] != NULL && _materia[i]->getType() == type)
		{
			std::cout << "MateriaSource created " << type << std::endl;
			return (_materia[i]->clone());
		}
	}	
	std::cout << "MateriaSource can't create " << type << std::endl;;
	return (0);
}

void    MateriaSource::_deleteMateriaSource(int idx)
{
    if (_materia[idx] != NULL)
    {
        delete _materia[idx];
        _materia[idx] = NULL;
    }
}