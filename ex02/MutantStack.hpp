#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T>>
class	MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack(const MutantStack &object);
		MutantStack	&operator=(const MutantStack &object);

		MutantStack(const Container &container);
		typename Container::iterator	begin(void);
		typename Container::iterator	end(void);
		typename Container::iterator	rbegin(void);
		typename Container::iterator	rend(void);
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void)
	: stack()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &object)
{
	*this = object;
}

template <typename T, typename Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=(const MutantStack &object)
{
	if (this == &object)
		return (*this);
	std::stack<T, Container>::operator=(object);
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const Container &container)
	: stack(container)
{
}

template <typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::begin(void)
{
	return (std::stack<T, Container>::c.begin());
}

template <typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::rbegin(void)
{
	return (std::stack<T, Container>::c.rbegin());
}

template <typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::end(void)
{
	return (std::stack<T, Container>::c.end());
}

template <typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::rend(void)
{
	return (std::stack<T, Container>::c.rend());
}

#endif