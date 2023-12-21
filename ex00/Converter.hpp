#ifndef CONVERTER_HPP 
# define CONVERTER_HPP 

# include <exception>
# include <string>

class	Converter	
{
	public: 
		Converter(void);
		~Converter(void);
		Converter(const Converter &object);
		Converter	&operator=(const Converter &object);
		
		static double	stringToDouble(const std::string &string) throw (std::exception);	
		static char		doubleToChar(const double doubleNumber) throw (std::exception);
		static int		doubleToInt(const double doubleNumber) throw (std::exception);
		static float	doubleToFloat(const double doubleNumber);

		class	UnconvertableException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class	UndisplayableException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};		

#endif