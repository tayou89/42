#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <fstream>
# include <string>
# include <stdexcept>
# include <ctime>

typedef struct InputData 
{
	std::string	date;
	double		priceValue;
}	InputData;

class	BitcoinExchange
{
	public:
		~BitcoinExchange(void);

		BitcoinExchange(const std::string exchangeRateFile);
		void	printExchangedValue(const std::string exchageValueFile);

	private:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &object);
		BitcoinExchange	&operator=(const BitcoinExchange &object);

		void	_openFile(std::ifstream &stream, const std::string &file); 
		void	_setExchangeRateMap(void);
		void	_setExchangeRateMapElement(const std::string &fileLine);
		void	_setInputData(const std::string &fileLine);
		double	_getExchangeRate(void) const;

		std::ifstream					_rateFileStream;	
		std::ifstream					_valueFileStream;
		std::map<std::string, double>	_exchangeRateMap;
		InputData						_inputData;
};

void	checkArgcException(const int &argc);

bool	isValidDate(const std::string &date);
bool	isValidDateFormat(const std::string &date);
bool	isValidTime(const std::tm &time);
std::tm	extractTime(const std::string &date);

bool	isValidPrice(double price);
bool	isDuplicateKey(const std::map<std::string, double> &map, const std::string &key);

void	ignoreOneLine(std::ifstream	&stream);

#endif