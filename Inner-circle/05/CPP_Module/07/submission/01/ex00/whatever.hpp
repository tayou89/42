#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &data1, T &data2)
{
	T	temp = data1;

	data1 = data2;
	data2 = temp;
}

template <typename T>
T	min(T data1, T data2)
{
	if (data1 < data2)
		return (data1);
	else
		return (data2);
}

template <typename T>
T	max(T data1, T data2)
{
	if (data1 > data2)
		return (data1);
	else
		return (data2);
}

#endif