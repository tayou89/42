#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <exception>

class	Converter
{
	public:
		~Converter(void);
		Converter	&operator=(const Converter &object);

		static char		convertToChar(const std::string &charLiteral);
		static char		convertToChar(const int &integer) throw (std::exception);
		static char		convertToChar(const float &floatNumber) throw (std::exception);
		static char		convertToChar(const double &doubleNumber) throw (std::exception);

		static int		convertToInt(const std::string &intLiteral);
		static int		convertToInt(const char &character);
		static int		convertToInt(const float &floatNumber) throw (std::exception);
		static int		convertToInt(const double &doubleNumber) throw (std::exception);

		static float	convertToFloat(const std::string &floatLiteral);
		static float	convertToFloat(const char &character);
		static float	convertToFloat(const int &integer);
		static float	convertToFloat(const double &doubleNumber);

		static double	convertToDouble(const std::string &doubleLiteral);
		static double	convertToDouble(const char &character);
		static double	convertToDouble(const int &integer);
		static double	convertToDouble(const float &doubleNumber);

		class	UnconvertableException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class	NonDisplayableException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	private:
		Converter(void);
		Converter(const Converter &object);
};

#endif