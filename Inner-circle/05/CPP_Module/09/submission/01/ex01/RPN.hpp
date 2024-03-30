#ifndef RPN_HPP
# define RPN_HPP

# include <list>
# include <string>
# include <stdexcept>

class	RPN
{
	public:
		~RPN(void);
		RPN	&operator=(const RPN &object);
		RPN(const char *reversePolishNotation);

		int	calculateRPN(void);	
	
	private:
		RPN(void);
		RPN(const RPN &object);

		void	_calculateIntegers(const char &operator_);

		bool	_isOperator(const char &c) const;
		bool	_isOutOfInt(long long number) const;

		int		_add(int number1, int number2) const;
		int		_subtract(int number1, int number2) const;
		int		_devide(int number1, int number2) const;
		int		_multiple(int number1, int number2) const;

		std::string		_RPNString;
		std::list<int>	_integers;
};

#endif