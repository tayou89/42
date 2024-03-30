#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdio>
# include <exception>

template <typename T>

class	Array
{
	public:
		Array(void);
		~Array(void);
		Array(const Array &object);
		Array	&operator=(const Array &object);

		Array(const unsigned int n);
		T	&operator[](const long long index);
		const T	&operator[](const long long index) const;
		unsigned int	size(void) const;

	private:
		unsigned int	arraySize;
		T				*element;
};

template <typename T>
Array<T>::Array(void)
	: arraySize(3), element(new T[arraySize]())
{
}

template <typename T>
Array<T>::~Array(void)
{
	delete []element;
}

template <typename T>
Array<T>::Array(const Array &object)
	: arraySize(object.size()), element(new T[arraySize])
{
	for (unsigned int i = 0; i < arraySize; i++)
		element[i] = object[i];
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &object)
{
	if (this == &object)
		return (*this);
	delete []element;
	arraySize = object.size();
	element = new T[arraySize];
	for (unsigned int i = 0; i < arraySize; i++)
		element[i] = object[i];
	return (*this);
}

template <typename T>
Array<T>::Array(const unsigned int n)
	: arraySize(n), element(new T[n]())
{
}

template <typename T>
T	&Array<T>::operator[](const long long index) 
{
	if (index < 0 || index >= size())
		throw std::exception();
	return (element[index]);
} 

template <typename T>
const T	&Array<T>::operator[](const long long index) const
{
	if (index < 0 || index >= size())
		throw std::exception();
	return (element[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (arraySize);
}

#endif