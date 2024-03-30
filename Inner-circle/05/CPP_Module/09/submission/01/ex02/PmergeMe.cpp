#include "PmergeMe.hpp"
#include <stdexcept>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <iomanip>

PmergeMe::PmergeMe(void)
	: _vectorElapsedTime(0.0), _dequeElapsedTime(0.0)
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
	_vectorInputIntegers = object._vectorInputIntegers;
	_vectorMainChain = object._vectorMainChain;
	_vectorSubChain = object._vectorSubChain;
	_vectorElapsedTime = object._vectorElapsedTime;

	_dequeInputIntegers = object._dequeInputIntegers;
	_dequeMainChain = object._dequeMainChain;
	_dequeSubChain = object._dequeSubChain;
	_dequeElapsedTime = object._dequeElapsedTime;
	return (*this);
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

void	PmergeMe::sortByVectorContainer(char *inputIntegers[])
{
	clock_t	startTime, endTime;

	startTime = std::clock();
	_setVectorInputIntegers(inputIntegers);
	_setVectorChains();
	_sortVectorMainChainByBinaryInsertion();
	_mergeVectorSubChainToMain();
	endTime = std::clock();
	_vectorElapsedTime 
		= (static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC) * 1000000.0;
}

void	PmergeMe::_setVectorInputIntegers(char *inputIntegers[])
{
	std::stringstream	stringStream;
	long long			number;
	int					integer;
	int					i = 0;

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
		if (_isVectorDuplicateNumber(integer) == true)
			throw (std::invalid_argument("Error: duplicate integer: " + std::string(inputIntegers[i])));
		_vectorInputIntegers.push_back(integer);
		stringStream.clear();
		stringStream.str("");
		i++;
	}
}

bool	PmergeMe::_isVectorDuplicateNumber(const int &number)
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

void	PmergeMe::_pushValuesToEachVectorChain(const int &number1, const int &number2)
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
	std::vector<int>::iterator	mainBeginPoint, subBeginPoint;
	int							mainValue, pairedValue;	
	int							insertIndex;
	int							mainChainSize = _vectorMainChain.size();
	int							i;

	for (i = 1; i < mainChainSize; i++)
	{
		mainValue = _vectorMainChain[i];
		pairedValue = _vectorSubChain[i];
		mainBeginPoint = _vectorMainChain.begin();
		subBeginPoint = _vectorSubChain.begin();
		insertIndex = _binarySearchVector(0, i - 1, mainValue);
		if (mainValue > _vectorMainChain[insertIndex])
			++insertIndex;
		_vectorMainChain.erase(mainBeginPoint + i);
		_vectorSubChain.erase(subBeginPoint + i);
		_vectorMainChain.insert(mainBeginPoint + insertIndex, mainValue);
		_vectorSubChain.insert(subBeginPoint + insertIndex, pairedValue);
	}
}

void	PmergeMe::_mergeVectorSubChainToMain(void)
{
	int	subChainLastIndex = _vectorSubChain.size() - 1;
	int previousStartIndex = 0;
	int startIndex;
	int sortCount = 0;

	_vectorMainChain.insert(_vectorMainChain.begin(), _vectorSubChain.front());
	++sortCount;
	while (previousStartIndex != subChainLastIndex)
	{
		++sortCount;
		startIndex = _fordJohnsonEquation(sortCount) - 1;
		if (startIndex > subChainLastIndex)
			startIndex = subChainLastIndex;
		_insertVectorSubChainToMain(sortCount, startIndex, previousStartIndex);
		previousStartIndex = startIndex;
	}
}

void	PmergeMe::_insertVectorSubChainToMain(int sortCount, int startIndex, int lastIndex)
{
	int lastSearchIndex = static_cast<int>(std::pow(2.0, sortCount)) - 2;
	int mainChainLastIndex = _vectorMainChain.size() - 1; 
	int insertIndex, insertValue;

	if (lastSearchIndex > mainChainLastIndex)
		lastSearchIndex = mainChainLastIndex;
	for (; startIndex > lastIndex; startIndex--)
	{
		insertValue = _vectorSubChain[startIndex];
		insertIndex = _binarySearchVector(0, lastSearchIndex, insertValue);
		if (insertValue > _vectorMainChain[insertIndex])
			++insertIndex;
		_vectorMainChain.insert(_vectorMainChain.begin() + insertIndex, insertValue);
	}
}

int	PmergeMe::_binarySearchVector(int first, int last, int target)
{
	int mid;

	if (last <= first)
		return (first);
	mid = (first + last) / 2;
	if (target < _vectorMainChain[mid])
		return (_binarySearchVector(first, mid - 1, target));
	else
		return (_binarySearchVector(mid + 1, last, target));
}

void	PmergeMe::sortByDequeContainer(char *inputIntegers[])
{
	clock_t	startTime, endTime;

	startTime = std::clock();
	_setDequeInputIntegers(inputIntegers);
	_setDequeChains();
	_sortDequeMainChainByBinaryInsertion();
	_mergeDequeSubChainToMain();
	endTime = std::clock();
	_dequeElapsedTime
		= (static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC) * 1000000.0;
}

void	PmergeMe::_setDequeInputIntegers(char *inputIntegers[])
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
		if (_isDequeDuplicateNumber(integer) == true)
			throw (std::invalid_argument("Error: duplicate integer: " + std::string(inputIntegers[i])));
		_dequeInputIntegers.push_back(integer);
		stringStream.clear();
		stringStream.str("");
		i++;
	}
}

bool	PmergeMe::_isDequeDuplicateNumber(const int &number)
{
	std::deque<int>::iterator	iterator = _dequeInputIntegers.begin();
	std::deque<int>::iterator	endPoint = _dequeInputIntegers.end();

	for (; iterator != endPoint; iterator++)
	{
		if (number == *iterator)
			return (true);
	}
	return (false);
}

void	PmergeMe::_setDequeChains(void)
{
	std::deque<int>::iterator	iterator = _dequeInputIntegers.begin();
	std::deque<int>::iterator	endPoint = _dequeInputIntegers.end();

	for (; iterator != endPoint; iterator++)
	{
		if (iterator + 1 != endPoint)
			_pushValuesToEachDequeChain(*iterator, *(++iterator));
		else
			_dequeSubChain.push_back(*iterator);
	}
}

void	PmergeMe::_pushValuesToEachDequeChain(const int &number1, const int &number2)
{
	if (number1 > number2)
	{
		_dequeMainChain.push_back(number1);
		_dequeSubChain.push_back(number2);
	}
	else
	{
		_dequeMainChain.push_back(number2);
		_dequeSubChain.push_back(number1);
	}
}

void	PmergeMe::_sortDequeMainChainByBinaryInsertion(void)
{
	int	mainValue, pairedValue;	
	int	mainChainSize = _dequeMainChain.size();
	int	insertIndex, i;

	for (i = 1; i < mainChainSize; i++)
	{
		mainValue = _dequeMainChain[i];
		pairedValue = _dequeSubChain[i];
		insertIndex = _binarySearchDeque(0, i - 1, mainValue);
		if (mainValue > _dequeMainChain[insertIndex])
			++insertIndex;
		_dequeMainChain.erase(_dequeMainChain.begin() + i);
		_dequeSubChain.erase(_dequeSubChain.begin() + i);
		_dequeMainChain.insert(_dequeMainChain.begin() + insertIndex, mainValue);
		_dequeSubChain.insert(_dequeSubChain.begin() + insertIndex, pairedValue);
	}
}

void	PmergeMe::_mergeDequeSubChainToMain(void)
{
	int	subChainLastIndex = _dequeSubChain.size() - 1;
	int	previousStartIndex = 0;
	int	startIndex;
	int	sortCount = 0;

	_dequeMainChain.insert(_dequeMainChain.begin(), _dequeSubChain.front());
	++sortCount;
	while (previousStartIndex != subChainLastIndex)
	{
		++sortCount;
		startIndex = _fordJohnsonEquation(sortCount) - 1;
		if (startIndex > subChainLastIndex)
			startIndex = subChainLastIndex;
		_insertDequeSubChainToMain(sortCount, startIndex, previousStartIndex);
		previousStartIndex = startIndex;
	}
}

void	PmergeMe::_insertDequeSubChainToMain(int sortCount, int startIndex, int lastIndex)
{
	int lastSearchIndex = static_cast<int>(std::pow(2.0, sortCount)) - 2;
	int	mainChainLastIndex = _dequeMainChain.size() - 1; 
	int	insertIndex, insertValue;

	if (lastSearchIndex > mainChainLastIndex)
		lastSearchIndex = mainChainLastIndex;
	for (; startIndex > lastIndex; startIndex--)
	{
		insertValue = _dequeSubChain[startIndex];
		insertIndex = _binarySearchDeque(0, lastSearchIndex, insertValue);
		if (insertValue > _dequeMainChain[insertIndex])
			++insertIndex;
		_dequeMainChain.insert(_dequeMainChain.begin() + insertIndex, insertValue);
	}
}

int	PmergeMe::_binarySearchDeque(int first, int last, int target)
{
	int mid;

	if (last <= first)
		return (first);
	mid = (first + last) / 2;
	if (target < _dequeMainChain[mid])
		return (_binarySearchDeque(first, mid - 1, target));
	else
		return (_binarySearchDeque(mid + 1, last, target));
}

int	PmergeMe::_fordJohnsonEquation(int number)
{
	if (number < 2)
		return (1);
	return (static_cast<int>(std::pow(2.0, number)) - _fordJohnsonEquation(number - 1));
}

void	PmergeMe::printSortResult(void) const
{
	const int	elementCount = _vectorInputIntegers.size();

	std::cout << "Before: "; _printVector(_vectorInputIntegers); std::cout << '\n';
	std::cout << "After: "; _printVector(_vectorMainChain); std::cout << '\n';
	std::cout << "Time to process a range of " << elementCount 
			  << " elements with std::vector: " << _vectorElapsedTime << " (micro second)\n";
	std::cout << "Time to process a range of " << elementCount 
	          << " elements with std::deque: " << _dequeElapsedTime << " (micro second)\n";
}

void	PmergeMe::_printVector(const std::vector<int> &vector) const
{
	std::vector<int>::const_iterator	iterator = vector.begin();
	std::vector<int>::const_iterator	endPoint = vector.end();

	for (; iterator != endPoint; iterator++)
		std::cout << *iterator << ' ';
}

void	PmergeMe::_printDeque(const std::deque<int> &deque) const
{
	std::deque<int>::const_iterator	iterator = deque.begin();
	std::deque<int>::const_iterator	endpoint = deque.end();

	for (; iterator != endpoint; iterator++)
		std::cout << *iterator << ' ';
}