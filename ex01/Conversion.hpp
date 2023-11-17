#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <sstream>

# define TRUE	1
# define FALSE	0

class	Conversion
{
	public:
		int				ToInt(const std::string);
		std::string		ToString(const int number);

	private:
		int				_IsStreamEmpty(void) const;
		void			_EmptyStream(void);
		
		std::stringstream	_stringStream;
};

#endif
