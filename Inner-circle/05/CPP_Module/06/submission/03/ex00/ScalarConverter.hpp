#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>

class	ScalarConverter
{
	public:
		~ScalarConverter(void);
		ScalarConverter	&operator=(const ScalarConverter &object);

		static void	convert(const std::string string);
	
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &object);
};

#endif