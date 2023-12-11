#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
}

IMateriaSource::~IMateriaSource(void)
{
}

IMateriaSource::IMateriaSource(const IMateriaSource &object)
{
	*this = object;
}

IMateriaSource	&IMateriaSource::operator=(const IMateriaSource &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}
