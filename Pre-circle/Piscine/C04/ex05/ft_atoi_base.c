/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:19:06 by tayou             #+#    #+#             */
/*   Updated: 2022/10/15 22:11:35 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_number(char *str, char *base, int *i, int *size)
{
	int		number;
	int		j;

	number = 0;
	j = 0;
	while (base[j] != '\0')
	{
		if (base[j] == str[*i])
		{
			number = number * (*size) + j;
			(*i)++;
			j = 0;
		}
		else
			j++;
	}
	return (number);
}

int	check_condition(char *base, int *size)
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

int	check_space_sign(char *str, int *i)
{
	int	sign;

	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
			(*i)++;
	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= (-1);
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	number;
	int	size;

	number = 0;
	i = 0;
	size = 0;
	while (base[size] != '\0')
		size++;
	if (size == 0 || size == 1)
		return (number);
	if (check_condition(base, &size) == 1)
		return (number);
	sign = check_space_sign(str, &i);
	number = get_number(str, base, &i, &size);
	return (sign * number);
}
/*
#include <stdio.h>

int     main()
{
        char    str[] = "   ---+-+fzxcvg";
		char	base[] = "abcdef";

		printf("str : %s\n", str);
		printf("base : %s\n", base);
		printf("number : %d\n", ft_atoi_base(str, base));
        return (0);
}
*/
