/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:50:02 by tayou             #+#    #+#             */
/*   Updated: 2022/10/15 22:13:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_number(long long number, char *base, int size)
{
	char	c;

	if (number != 0)
	{
		c = base[number % size];
		number /= size;
		convert_number(number, base, size);
		write(1, &c, 1);
	}
}	

void	check_sign(long long *number)
{
	if (*number < 0)
	{
		*number *= (-1);
		write(1, "-", 1);
	}
}

int	check_same(char *base, int *size)
{
	int	i;
	int	j;

	i = 0;
	while (i < *size - 1)
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if ((base[i] == base[j]) || (base[i] == '+')
				|| (base[i] == '-') || (base[j] == '+')
				|| (base[j] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			size;
	long long	number;

	number = (long long) nbr;
	size = 0;
	while (base[size] != '\0')
		size++;
	if (size == 0 || size == 1)
		return ;
	if (check_same(base, &size) == 1)
		return ;
	if (number == 0)
		write(1, &base[0], 1);
	check_sign(&number);
	convert_number(number, base, size);
}
/*
int	main(void)
{
	char	*str = "01";
	int		nbr = 10;

	ft_putnbr_base(nbr, str);
	return (0);
}
*/
