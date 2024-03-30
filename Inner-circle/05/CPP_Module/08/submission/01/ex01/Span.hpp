#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class	Span
{
	public:
		Span(void);
		~Span(void);
		Span(const Span &object);
		Span	&operator=(const Span &object);

		Span(const unsigned int &N);
		void				addNumber(const int &number) throw (std::exception);
		unsigned int		shortestSpan(void) const throw (std::exception);
		unsigned int		longestSpan(void) const throw (std::exception);
		unsigned int		getMaxSize(void) const;
		std::vector<int>	getIntegers(void) const;

		template <typename Container>
		void				addManyNumbers(Container integerContainer) throw (std::exception);

	private:
		unsigned int		_maxSize;
		std::vector<int>	_integers;
};

template <typename Container>
void	Span::addManyNumbers(Container integerContainer) throw (std::exception)
{
	if (_integers.size() + integerContainer.size() > _maxSize)
		throw (std::length_error("Fail to add numbers: not enough starage"));
	_integers.insert(_integers.end(), integerContainer.begin(), integerContainer.end());
}

#endif