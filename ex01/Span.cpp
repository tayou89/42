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

void	Span::addNumber(const int &number) throw (std::exception)
{
	if (_integers.size() >= _maxSize)
		throw (std::length_error("Fail to add number: storage is already full"));
	_integers.push_back(number);
}

int	Span::shortestSpan(void) throw (std::exception)
{
	int							shortestSpan = std::numeric_limits<int>::max();
	std::vector<int>::iterator	currentPoint;
	std::vector<int>::iterator	nextPoint;		
	std::vector<int>::iterator	endPoint = _integers.end();

	if (_integers.size() < 2)
		throw (std::logic_error("Can't get shortest span: too few integers"));
	for (currentPoint = _integers.begin(); (currentPoint + 1) != endPoint; currentPoint++)
	{
		nextPoint = currentPoint + 1;
		shortestSpan = std::min(shortestSpan, *currentPoint - *nextPoint);

	} 
}