#include "PergeMe.hpp"
#include <stdexcept>
#include <sstream>
#include <limits>
#include <cstdlib>

PergeMe::PergeMe(void)
{
}

PergeMe::~PergeMe(void)
{
}

PergeMe::PergeMe(const PergeMe &object)
{
	*this = object;
}

PergeMe	&PergeMe::operator=(const PergeMe &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}

PergeMe::PergeMe(const char *inputIntegers[])
{
	_setVectorInputIntegers(inputIntegers);
	_setDequeInputIntegers();
}


void	PergeMe::_setVectorInputIntegers(const char *inputIntegers[])
{
	std::stringstream	stringStream;
	long long			number;
	int					integer;
	size_t				i;

	if (inputIntegers[0] == NULL)
		throw (std::invalid_argument("Error: no integers to sort"));
	while (inputIntegers[i] != NULL)
	{
		stringStream << inputIntegers[i];
		stringStream >> number;
		if (stringStream.fail() == true || stringStream.eof() == false)
			throw (std::invalid_argument("Error: wrong input: " + std::string(inputIntegers[i])));
		if (_isOutOfInt(number) == true)
			throw (std::range_error("Error: out of int: " + std::string(inputIntegers[i])));
		integer = std::atoi(inputIntegers[i]);
		if (_isPositiveInteger(integer) == false)
			throw (std::invalid_argument("Error: not a positive integer: " + std::string(inputIntegers[i])));
		if (_isDuplicateNumber(integer) == true)
			throw (std::invalid_argument("Error: duplicate integer: " + std::string(inputIntegers[i])));
		_vectorInputIntegers.push_back(integer);
		stringStream.clear();
		stringStream.str("");
	}
}

void	PergeMe::_setDequeInputIntegers(void)
{
	_dequeInputIntegers.assign(_vectorInputIntegers.begin(), _vectorInputIntegers.end());
}


bool	PergeMe::_isOutOfInt(const long long &number)
{
	long long	intMAX = std::numeric_limits<int>::max();
	long long	intMIN = std::numeric_limits<int>::min();

	if (number < intMIN || number > intMAX)
		return (false);
	return (true);
}


bool	PergeMe::_isPositiveInteger(const int &number)
{
	if (number <= 0)
		return (false);
	return (true);
}


bool	PergeMe::_isDuplicateNumber(const int &number)
{
	std::vector<int>::iterator	iterator = _vectorInputIntegers.begin();
	std::vector<int>::iterator	endPoint = _vectorInputIntegers.end();

	for (; iterator != endPoint; iterator++)
	{
		if (number == *iterator)
			return (true);
	}
	return (false);
}

void	PergeMe::sortByVectorContainer(void)
{
	_setVectorChains();
	_sortVectorMainChainByBinaryInsertion();
}

void	PergeMe::_setVectorChains(void)
{
	std::vector<int>::iterator	iterator = _vectorInputIntegers.begin();
	std::vector<int>::iterator	endPoint = _vectorInputIntegers.end();

	for (; iterator != endPoint; iterator++)
	{
		if (iterator + 1 != endPoint)
			_pushValuesToEachVectorChain(*iterator, *(iterator++));
		else
			_vectorPairedChain.push_back(*iterator);
	}
}

void	PergeMe::_pushValuesToEachVectorChain(int number1, int number2)
{
	if (number1 > number2)
	{
		_vectorMainChain.push_back(number1);
		_vectorPairedChain.push_back(number2);
	}
	else
	{
		_vectorMainChain.push_back(number2);
		_vectorPairedChain.push_back(number1);
	}
}

void	PergeMe::_sortVectorMainChainByBinaryInsertion(void)
{
	size_t	insertIndex;
	size_t	firstIndex = 0, lastIndex;
	size_t	i;
	int		mainValue, pairedValue;	

	for (i = 1; i < _vectorMainChain.size(); i++)
	{
		mainValue = _vectorMainChain[i];
		pairedValue = _vectorPairedChain[i];
		lastIndex = i - 1;
		_eraseValuesFromChains(i);
		insertIndex = _binarySearchVector(_vectorMainChain, firstIndex, lastIndex, mainValue);
		_insertValuesToChains(insertIndex, mainValue, pairedValue);
	}
}

void	PergeMe::_eraseValuesFromChains(size_t &targetIndex)
{
	_vectorMainChain.erase(_vectorMainChain.begin() + targetIndex);
	_vectorPairedChain.erase(_vectorPairedChain.begin() + targetIndex);
}

size_t	PergeMe::_binarySearchVector(std::vector<int> vector, size_t first, size_t last, int target)
{
	size_t	mid;

	if (last <= first)
		return (first);
	mid = (first + last) / 2;
	if (target < vector[mid])
		return (_binarySearchVector(vector, first, mid - 1, target));
	else
		return (_binarySearchVector(vector, mid + 1, last, target));
}

void	PergeMe::_insertValuesToChains(size_t insertIndex, int &mainValue, int &pairedValue)
{
	if (mainValue > _vectorMainChain[insertIndex])
		++insertIndex;
	_vectorMainChain.insert(_vectorMainChain.begin() + insertIndex, mainValue);
	_vectorMainChain.insert(_vectorPairedChain.begin() + insertIndex, pairedValue);
}