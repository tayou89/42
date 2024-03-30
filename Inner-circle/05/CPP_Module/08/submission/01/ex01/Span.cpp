#include "Span.hpp"
#include <limits>
#include <algorithm>

Span::Span(void)
	: _maxSize(0)
{
}

Span::~Span(void)
{
}

Span::Span(const Span &object)
{
	*this = object;
}

Span	&Span::operator=(const Span &object)
{
	if (this == &object)
		return (*this);
	_maxSize = object.getMaxSize();
	_integers = object.getIntegers();
	return (*this);
}

Span::Span(const unsigned int &N)
	: _maxSize(N)
{
}

void	Span::addNumber(const int &number) throw (std::exception)
{
	if (_integers.size() >= _maxSize)
		throw (std::length_error("Fail to add number: storage is already full"));
	_integers.push_back(number);
}

unsigned int	Span::shortestSpan(void) const throw (std::exception)
{
	std::vector<int>			copyIntegers = _integers;
	std::vector<int>::iterator	point;
	unsigned int				shortestSpan = std::numeric_limits<unsigned int>::max();
	unsigned int				newSpan = 0;

	if (_integers.size() < 2)
		throw (std::logic_error("Can't get shortest span: too few integers"));
	std::sort(copyIntegers.begin(), copyIntegers.end());
	for (point = copyIntegers.begin(); (point + 1) != copyIntegers.end(); point++)
	{
		newSpan = *(point + 1) - *point;
		shortestSpan = std::min(shortestSpan, newSpan);
	}
	return (shortestSpan);
}

unsigned int	Span::longestSpan(void) const throw (std::exception)
{
	std::vector<int>	copyIntegers = _integers;

	if (_integers.size() < 2)
		throw (std::logic_error("Can't get longest span: too few integers"));
	std::sort(copyIntegers.begin(), copyIntegers.end());
	return (*(copyIntegers.end() - 1) - *copyIntegers.begin());
}

unsigned int	Span::getMaxSize(void) const
{
	return (_maxSize);
}

std::vector<int>	Span::getIntegers(void) const
{
	return (_integers);
}