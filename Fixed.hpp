#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &origin);
		Fixed	&operator=(const Fixed &origin);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					fixedPointValue;
		static const int	fractionalBitCount = 8;
};

#endif
