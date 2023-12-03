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

		bool	operator>(const Fixed &object) const;
		bool	operator<(const Fixed &object) const;
		bool	operator>=(const Fixed &object) const;
		bool	operator<=(const Fixed &object) const;
		bool	operator==(const Fixed &object) const;
		bool	operator!=(const Fixed &object) const;

		Fixed	operator+(const Fixed &object) const;
		Fixed	operator-(const Fixed &object) const;
		Fixed	operator*(const Fixed &object) const;
		Fixed	operator/(const Fixed &object) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed		&min(Fixed &number1, Fixed &number2);
		static const Fixed	&min(const Fixed &number1, const Fixed &number2);
		static Fixed		&max(Fixed &number1, Fixed &number2);
		static const Fixed	&max(const Fixed &number1, const Fixed &number2);

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &object);

#endif
