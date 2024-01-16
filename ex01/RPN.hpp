#ifndef RPN_HPP
# define RPN_HPP

# include <list>
# include <string>

class	RPN
{
	public:
		RPN(void);
		~RPN(void);
		RPN(const RPN &object);
		RPN	&operator=(const RPN &object);
	
	private:
		std::string		reversePolishNotation;
		std::list<int>	integers;
};

#endif