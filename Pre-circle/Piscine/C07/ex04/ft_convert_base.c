/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:38:23 by tayou             #+#    #+#             */
/*   Updated: 2022/10/20 17:41:13 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*putnbr_base(long long number, char *base_to, int to_size);

long long	get_number(char *str, char *base, int *i, int size)
{
	long long	number;
	int			j;

	number = 0;
	j = 0;
	while (base[j] != '\0')
	{
		if (base[j] == str[*i])
		{
			number = (number * size) + j;
			(*i)++;
			j = 0;
		}
		else
			j++;
	}
	return (number);
}

int	check_space_sign(char *str, int *i, char *base_from)
{
	int	sign;
	int	j;

	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
			(*i)++;
	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= (-1);
		(*i)++;
	}
	j = 0;
	while (base_from[j] != '\0')
	{
		if (base_from[j] == str[*i])
			return (sign);
		else
			j++;
	}
	return (0);
}

int	check(char *base, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if ((base[i] == base[j]) || (base[i] == '+')
				|| (base[i] == '-') || (base[j] == '+')
				|| (base[j] == '-') || (base[i] == 32)
				|| (base[i] >= 9 && base[i] <= 13)
				|| (base[j] == 32) || (base[j] >= 9 && base[j] <= 13))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			from_size;
	int			to_size;
	int			i;
	long long	number;
	char		*array;

	from_size = 0;
	while (base_from[from_size] != '\0')
		from_size++;
	to_size = 0;
	while (base_to[to_size] != '\0')
		to_size++;
	if (from_size <= 1 || to_size <= 1)
		return (0);
	if (check(base_from, from_size) == 1 || check(base_to, to_size) == 1)
		return (0);
	i = 0;
	number = check_space_sign(nbr, &i, base_from);
	number = number * get_number(nbr, base_from, &i, from_size);
	array = putnbr_base(number, base_to, to_size);
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	char	*nbr = "	  -+---+- 5239aerab";
	char	*base_from = "012345";
	char	*base_to = "0123487";
	
	printf("nbr : %s\n", nbr);
	printf("base_from : %s\n", base_from);
	printf("base_to : %s\n", base_to);
	printf("array : %s\n", ft_convert_base(nbr, base_from, base_to));
	return (0);
}
*/
