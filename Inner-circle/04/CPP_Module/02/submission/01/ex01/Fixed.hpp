#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class	Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &origin);
		Fixed	&operator=(const Fixed &origin);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed(const int number);
		Fixed(const float number);
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &object);

#endif
