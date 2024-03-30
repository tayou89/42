#ifndef SCALAR_PRINTER_HPP
# define SCALAR_PRINTER_HPP

# include <exception>

class	ScalarPrinter
{
	public:
		~ScalarPrinter(void);
		ScalarPrinter	&operator=(const ScalarPrinter &object);

		static void	printScalar(const char &character);
		static void	printScalar(const int &integer);
		static void	printScalar(const float &floatNumber);
		static void	printScalar(const double &doubleNumber);
		static void	printScalar(const std::exception &exception);

	private:
		ScalarPrinter(void);
		ScalarPrinter(const ScalarPrinter &object);

		static void	printChar(const char &character);
		static void	printChar(const std::exception &exception);

		static void	printInt(const int &integer);
		static void	printInt(const std::exception &exception);
		
		static void	printFloat(const float &floatNumber);
		static void	printFloat(const std::exception &exception);

		static void	printDouble(const double &doubleNumber);
		static void	printDouble(const std::exception &exception);
}; 

#endif