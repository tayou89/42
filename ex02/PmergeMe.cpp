#include "PmergeMe.hpp"
#include <stdexcept>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iostream>

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &object)
{
	*this = object;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}

PmergeMe::PmergeMe(char *inputIntegers[])
{
	_setVectorInputIntegers(inputIntegers);
	_setDequeInputIntegers();
}


void	PmergeMe::_setVectorInputIntegers(char *inputIntegers[])
{
	std::stringstream	stringStream;
	long long			number;
	int					integer;
	size_t				i = 0;

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
		i++;
	}
}

void	PmergeMe::_setDequeInputIntegers(void)
{
	_dequeInputIntegers.assign(_vectorInputIntegers.begin(), _vectorInputIntegers.end());
}


bool	PmergeMe::_isOutOfInt(const long long &number)
{
	long long	intMAX = std::numeric_limits<int>::max();
	long long	intMIN = std::numeric_limits<int>::min();

	if (number < intMIN || number > intMAX)
		return (true);
	return (false);
}


bool	PmergeMe::_isPositiveInteger(const int &number)
{
	if (number <= 0)
		return (false);
	return (true);
}


bool	PmergeMe::_isDuplicateNumber(const int &number)
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

void	PmergeMe::sortByVectorContainer(void)
{
	_setVectorChains();
	_printVector(_vectorInputIntegers); std::cout << '\n';
	_printVector(_vectorMainChain); std::cout << '\n';
	_printVector(_vectorSubChain); std::cout << '\n';
	_sortVectorMainChainByBinaryInsertion();
	_mergeVectorSubChainToMain();
}

void	PmergeMe::_setVectorChains(void)
{
	std::vector<int>::iterator	iterator = _vectorInputIntegers.begin();
	std::vector<int>::iterator	endPoint = _vectorInputIntegers.end();

	for (; iterator != endPoint; iterator++)
	{
		if (iterator + 1 != endPoint)
			_pushValuesToEachVectorChain(*iterator, *(++iterator));
		else
			_vectorSubChain.push_back(*iterator);
	}
}

void	PmergeMe::_pushValuesToEachVectorChain(int number1, int number2)
{
	if (number1 > number2)
	{
		_vectorMainChain.push_back(number1);
		_vectorSubChain.push_back(number2);
	}
	else
	{
		_vectorMainChain.push_back(number2);
		_vectorSubChain.push_back(number1);
	}
}

void	PmergeMe::_sortVectorMainChainByBinaryInsertion(void)
{
	size_t	insertIndex;
	size_t	firstIndex = 0, lastIndex;
	size_t	i;
	int		mainValue, pairedValue;	

	for (i = 1; i < _vectorMainChain.size(); i++)
	{
		mainValue = _vectorMainChain[i];
		pairedValue = _vectorSubChain[i];
		lastIndex = i - 1;
		_eraseValuesFromChains(i);
		insertIndex = _binarySearchVector(firstIndex, lastIndex, mainValue);
		_insertValuesToChains(insertIndex, mainValue, pairedValue);
	}
}

void	PmergeMe::_eraseValuesFromChains(size_t &targetIndex)
{
	_vectorMainChain.erase(_vectorMainChain.begin() + targetIndex);
	_vectorSubChain.erase(_vectorSubChain.begin() + targetIndex);
}

size_t	PmergeMe::_binarySearchVector(size_t first, size_t last, int target)
{
	size_t	mid;

	if (last <= first)
		return (first);
	mid = (first + last) / 2;
	if (target < _vectorMainChain[mid])
		return (_binarySearchVector(first, mid - 1, target));
	else
		return (_binarySearchVector(mid + 1, last, target));
}

void	PmergeMe::_insertValuesToChains(size_t insertIndex, int &mainValue, int &pairedValue)
{
	if (mainValue > _vectorMainChain[insertIndex])
		++insertIndex;
	_vectorMainChain.insert(_vectorMainChain.begin() + insertIndex, mainValue);
	_vectorSubChain.insert(_vectorSubChain.begin() + insertIndex, pairedValue);
}

void	PmergeMe::_mergeVectorSubChainToMain(void)
{
	size_t	subChainLastIndex = _vectorSubChain.size() - 1;
	size_t	lastStartIndex = 0;
	size_t	startIndex;
	size_t	sortCount = 0;

	_vectorMainChain.insert(_vectorMainChain.begin(), _vectorSubChain.front());
	++sortCount;
	while (lastStartIndex != subChainLastIndex)
	{
		++sortCount;
		startIndex = _fordJohnsonEquation(sortCount) - 1;
		if (startIndex > subChainLastIndex)
			startIndex = subChainLastIndex;
		_insertVectorSubToMainChain(sortCount, startIndex, lastStartIndex);
		lastStartIndex = startIndex;
	}
}

void	PmergeMe::_insertVectorSubToMainChain(size_t sortCount, size_t startIndex, size_t lastIndex)
{
	size_t	lastIndexToSort = static_cast<size_t>(std::pow(2.0, sortCount)) - 1;
	size_t	mainChainLastIndex = _vectorMainChain.size() - 1; 
	size_t	insertIndex;
	int		insertValue;

	if (lastIndexToSort > mainChainLastIndex)
		lastIndexToSort = mainChainLastIndex;
	for (; startIndex > lastIndex; startIndex--)
	{
		insertValue = _vectorSubChain[startIndex];
		insertIndex = _binarySearchVector(0, lastIndexToSort, insertValue);
		if (insertValue > _vectorMainChain[insertIndex])
			++insertIndex;
		_vectorMainChain.insert(_vectorMainChain.begin() + insertIndex, insertValue);
	}
}

size_t	PmergeMe::_fordJohnsonEquation(size_t number)
{
	if (number < 2)
		return (1);
	return (static_cast<int>(std::pow(2.0, number)) - _fordJohnsonEquation(number - 1));
}

void	PmergeMe::printVectorMainChain(void) const
{
	_printVector(_vectorMainChain);
}

void	PmergeMe::printVectorInputIntegers(void) const
{
	_printVector(_vectorInputIntegers);
}

void	PmergeMe::_printVector(const std::vector<int> &vector) const
{
	std::vector<int>::const_iterator	iterator = vector.begin();
	std::vector<int>::const_iterator	endPoint = vector.end();

	for (; iterator != endPoint; iterator++)
		std::cout << *iterator << ' ';
}