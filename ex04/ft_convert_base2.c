/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:11:41 by tayou             #+#    #+#             */
/*   Updated: 2022/10/20 00:06:22 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	get_array_size(long long number, int to_size)
{
	long long	i;

	if (number == 0)
		return (1);
	i = 0;
	if (number < 0)
	{
		i += 1;
		number *= (-1);
	}
	while (number != 0)
	{
		number /= to_size;
		i++;
	}
	return (i);
}

char	*putnbr_base(long long number, char *base_to, int to_size)
{
	char		*array;
	long long	array_size;
	long long	i;

	array_size = get_array_size(number, to_size);
	array = (char *)malloc(array_size * sizeof(char) + 1);
	if (number == 0)
	{
		array[0] = base_to[0];
		return (array);
	}
	if (number < 0)
	{
		array[0] = '-';
		number *= (-1);
	}
	i = 1;
	while (number != 0)
	{
		array[array_size - i] = base_to[number % to_size];
		number /= to_size;
		i++;
	}
	array[array_size] = '\0';
	return (array);
}
