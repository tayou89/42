#ifndef SCALAR_PRINTER_HPP
# define SCALAR_PRINTER_HPP

# include <exception>

class	ScalarPrinter	
{
	public:
		ScalarPrinter(void);
		~ScalarPrinter(void);
		ScalarPrinter(const ScalarPrinter &object);
		ScalarPrinter	&operator=(const ScalarPrinter &object);

		static void	printChar(const char &character);
		static void	printInt(const int &integer);
		static void	printFloat(const float &floatNumber);
		static void	printDouble(const double &doubleNumber);

		static void	printChar(const std::exception &exception);
		static void	printInt(const std::exception &exception);
		static void	printFloat(const std::exception &exception);
		static void	printDouble(const std::exception &exception);
};		

#endif