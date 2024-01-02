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

		char	convertToChar(const std::string &charLiteral);

		
	private:
		char	character;
		int		integer;
		float	floatNumber;
		double	doubleNumber;
};		

#endif