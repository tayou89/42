#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <limits>

RPN::RPN(void) {};

RPN::~RPN(void) {};

RPN::RPN(const RPN &object)
{
	*this = object;
}

RPN	&RPN::operator=(const RPN &object)
{
	if (this == &object)
		return (*this);
	_RPNString = object._RPNString;
	_integers = object._integers;
	return (*this);
}

RPN::RPN(const char *reversePolishNotation)
{
	if (reversePolishNotation == NULL)
		throw (std::invalid_argument("Error: RPN expression is needed"));
	_RPNString = reversePolishNotation;
}

int	RPN::calculateRPN(void)
{
	std::stringstream	stringStream(_RPNString);
	std::string			string;
	size_t				stringCount = 0;

	while (stringStream >> string)
	{
		++stringCount;
		if (string.size() > 1)
			throw (std::runtime_error("Error: wrong RPN format"));
		if (std::isdigit(string[0]) == true)
			_integers.push_back(std::atoi(string.c_str()));
		else if (_isOperator(string[0]) == true)
			_calculateIntegers(string[0]);
		else
			throw (std::runtime_error("Error: undefined character: " + string));
	}
	if (stringCount == 0)
		throw (std::runtime_error("Error: no data to calculate"));
	if (_integers.size() != 1)
		throw (std::runtime_error("Error: need more operator"));
	return (_integers.back());
}

bool	RPN::_isOperator(const char &c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/'); 
}

void	RPN::_calculateIntegers(const char &operator_)
{
	int	number1, number2;
	int	result;

	if (_integers.size() < 2)
		throw (std::runtime_error("Error: can't calculate: not enough integers"));
	number2 = _integers.back();
	_integers.pop_back();
	number1 = _integers.back();
	_integers.pop_back();
	if (operator_ == '+')
		result = _add(number1, number2);
	else if (operator_ == '-')
		result = _subtract(number1, number2);
	else if (operator_ == '*')
		result = _multiple(number1, number2);
	else
		result = _devide(number1, number2);
	_integers.push_back(result);
}

int	RPN::_add(int number1, int number2) const
{
	if (_isOutOfInt(static_cast<long long>(number1) + static_cast<long long>(number2)))
		throw (std::range_error("Error: can't calculate: out of int range"));
	return (number1 + number2);
}

int	RPN::_subtract(int number1, int number2) const
{
	if (_isOutOfInt(static_cast<long long>(number1) - static_cast<long long>(number2)))
		throw (std::range_error("Error: can't calculate: out of int range"));
	return (number1 - number2);
}

int	RPN::_devide(int number1, int number2) const
{
	if (number2 == 0)
		throw (std::logic_error("Error: can't devide by 0"));
	return (number1 / number2);
}

int	RPN::_multiple(int number1, int number2) const
{
	if (_isOutOfInt(static_cast<long long>(number1) * static_cast<long long>(number2)))
		throw (std::range_error("Error: can't calculate: out of int range"));
	return (number1 * number2);
}

bool	RPN::_isOutOfInt(long long number) const
{
	long long	intMAX = std::numeric_limits<int>::max();
	long long	intMIN = std::numeric_limits<int>::min();

	if (number < intMIN || number > intMAX)
		return (true);
	else
		return (false);
}