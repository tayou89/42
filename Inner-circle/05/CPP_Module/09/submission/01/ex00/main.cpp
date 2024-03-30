#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	try
	{
		BitcoinExchange	bitcoinExchange("data.csv");
		const char		*exchangeValueFile = argv[1];
		
		checkArgcException(argc);
		bitcoinExchange.printExchangedValue(exchangeValueFile);		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}