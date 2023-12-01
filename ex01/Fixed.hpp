#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &origin);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed(void);

		Fixed	&operator=(const Fixed &origin);
		int		getFixedPointValue(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		void	_setFixedPointValue(int number);

		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &object);

#endif
