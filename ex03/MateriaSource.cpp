#include "MateriaSource.hpp"

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

	for (i = 0; i < _materiaMaxCount; i++)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = aMateriaPTR;
			return ;
		}
	}
	if (aMateriaPTR != NULL)
		delete aMateriaPTR;
}


AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i;

	for (i = 0; i < _materiaMaxCount; i++)
	{
		if (_materia[i] != NULL && _materia[i]->getType() == type)
			return (_materia[i]->clone());
	}	
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