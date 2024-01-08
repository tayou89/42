#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class	Span
{
	public:
		Span(void);
		~Span(void);
		Span(const Span &object);
		Span	&operator=(const Span &object);

		void				addNumber(const int &number) throw (std::exception);
		int					shortestSpan(void) throw (std::exception);
		int					longestSpan(void) throw (std::exception);
		unsigned int		getMaxSize(void) const;
		std::vector<int>	getIntegers(void) const;

	private:
		unsigned int		_maxSize;
		std::vector<int>	_integers;
};

#endif