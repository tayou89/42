#include "BitcoinExchange.hpp"
#include <sstream>
#include <cctype>
#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) 
{
	if (_rateFileStream.is_open() == true)
		_rateFileStream.close();
	if (_valueFileStream.is_open() == true)
		_valueFileStream.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &object)
{
	*this = object;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &object)
{
	if (this == &object)
		return (*this);
	_exchangeRateMap = object._exchangeRateMap;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const std::string exchangeRateFile)
{
	_openFile(_rateFileStream, exchangeRateFile);
	_setExchangeRateMap();
	if (_exchangeRateMap.empty() == true)
		throw (std::runtime_error("Error: no rate data exists"));
	_rateFileStream.close();
}

void	BitcoinExchange::_openFile(std::ifstream &stream, const std::string &file)
{
	stream.open(file.c_str());
	if (stream.is_open() == false)
		throw (std::runtime_error("Error: failed to open: " + file));
}

void	BitcoinExchange::_setExchangeRateMap(void)
{
	std::string			fileLine;

	ignoreOneLine(_rateFileStream);
	while (std::getline(_rateFileStream, fileLine))
		_setExchangeRateMapElement(fileLine);
}

void	BitcoinExchange::_setExchangeRateMapElement(const std::string &fileLine)
{
	std::stringstream	stringStream(fileLine);
	std::string			string, date, rate;
	char				*endString = NULL;
	double				rateValue;
	size_t				stringCount = 0;
	size_t				seperatorIndex;

	while (stringStream >> string)
	{
		++stringCount;
		if (stringCount > 1)
			throw (std::runtime_error("Error: wrong data: " + fileLine));
		seperatorIndex = string.find(",");
		if (seperatorIndex == std::string::npos)
			throw (std::runtime_error("Error: no comma: " + fileLine));
		date = string.substr(0, seperatorIndex);
		if (isValidDate(date) == false)
			throw (std::runtime_error("Error: wrong date: " + date));
		rate = string.substr(seperatorIndex + 1);
		rateValue = std::strtod(rate.c_str(), &endString);
		if (rateValue < 0.0 || endString[0] != '\0')
			throw (std::runtime_error("Error: wrong rate: " + rate));
		if (isDuplicateKey(_exchangeRateMap, date) == true)
			throw (std::runtime_error("Error: duplicate date: " + date)); 
		_exchangeRateMap[date] = rateValue;
	}
}

void	BitcoinExchange::printExchangedValue(const std::string exchangeValueFile)
{
	std::string	fileLine;

	_openFile(_valueFileStream, exchangeValueFile);
	ignoreOneLine(_valueFileStream);
	while (std::getline(_valueFileStream, fileLine))
	{
		try
		{
			double	exchangeRate;

			_setInputData(fileLine);
			exchangeRate = _getExchangeRate();
			std::cout << _inputData.date << " => " 
					  << _inputData.priceValue << " = "
					  << _inputData.priceValue * exchangeRate << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	_valueFileStream.close();
}

void	BitcoinExchange::_setInputData(const std::string &fileLine)
{
	std::stringstream	stringStream(fileLine);
	std::string			string, seperator;
	char				*restString = NULL;
	size_t				stringCount = 0;

	while (stringStream >> string)
	{
		++stringCount;
		switch (stringCount)
		{
		case (1):
			_inputData.date = string;
			if (isValidDate(_inputData.date) == false)
				throw (std::runtime_error("Error: wrong date: " + _inputData.date));
			break ;
		case (2):
			seperator = string;
			if (seperator != "|")
				throw (std::runtime_error("Error: wrong format: " + fileLine));
			break ;
		case (3):
			_inputData.priceValue = std::strtod(string.c_str(), &restString);
			if (restString[0] != '\0' || isValidPrice(_inputData.priceValue) == false)
				throw (std::runtime_error("Error: price must be a number(0 ~ 1000): " + string));
			break ;
		default :
			throw (std::runtime_error("Error: wrong format: " + fileLine));
		}
	}
	if (stringCount < 3)
		throw (std::runtime_error("Error: wrong format: " + fileLine));
}

double	BitcoinExchange::_getExchangeRate(void) const
{
	std::map<std::string, double>::const_iterator iterator = _exchangeRateMap.begin();
	std::map<std::string, double>::const_iterator endPoint = _exchangeRateMap.end();

	for (;iterator != endPoint && iterator->first < _inputData.date; iterator++);
	if (iterator == _exchangeRateMap.begin())
		throw (std::runtime_error("Error: coundln't find exchage rate"));
	if (iterator == endPoint || iterator->first > _inputData.date)
		return ((--iterator)->second);
	else
		return (iterator->second);
}



void	checkArgcException(const int &argc)
{
	if (argc < 2)
		throw (std::invalid_argument("Error: too few argument"));
}

bool	isValidDate(const std::string &date)
{
	std::tm	time;

	if (isValidDateFormat(date) == false)
		return (false);
	time = extractTime(date);
	if (isValidTime(time) == false)
		return (false);
	return (true);
}

bool	isValidDateFormat(const std::string &date)
{
	size_t	i;

	if (date.size() != 10)
		return (false);
	for (i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return (false);
		}
		else
		{
			if (std::isdigit(date[i]) == false)
				return (false);
		}	
	}
	return (true);
}

std::tm	extractTime(const std::string &date)
{
	std::tm				time;
	std::stringstream	stringStream(date);
	int					number;
	int					numberCount = 0;

	while (stringStream >> number)
	{
		++numberCount;
		switch (numberCount)
		{
		case (1):
			time.tm_year = number;
			break ;
		case (2):
			time.tm_mon = number;
			break ;
		default :
			time.tm_mday = number;
		}
		stringStream.ignore();
	}
	return (time);
}

bool	isValidTime(const std::tm &time)
{
	int	year = time.tm_year;
	int	month = time.tm_mon;
	int	day = time.tm_mday;

	bool	isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int		daysInMonth[] = {0, 31, 28 + isLeapYear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return (false);
	if (day <= daysInMonth[month])
		return (true);
	else
		return (false);
}

bool	isValidPrice(double price)
{
	if (price < 0.0 || price > 1000.0)
		return (false);
	return (true);
}

bool	isDuplicateKey(const std::map<std::string, double> &map, const std::string &key)
{
	std::map<std::string, double>::const_iterator	iterator; 

	for (iterator = map.begin(); iterator != map.end(); iterator++)
	{
		if (iterator->first == key)
			return (true);
	}
	return (false);
}

void	ignoreOneLine(std::ifstream &stream)
{
	stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}