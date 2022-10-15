/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:55:11 by tayou             #+#    #+#             */
/*   Updated: 2022/10/14 21:36:29 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_number(char *str, int *i)
{
	int	number;

	number = 0;
	while ((str[*i] >= '0') && (str[*i] <= '9'))
	{
		number = number * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (number);
}

int	check_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= (-1);
		(*i)++;
	}
	return (sign);
}

void	check_whitespace(char *str, int *i)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	number = 0;
	i = 0;
	check_whitespace(str, &i);
	sign = check_sign(str, &i);
	if (str[i] < '0' && str[i] > '9')
		return (number);
	number = check_number(str, &i);
	return (sign * number);
}
/*
#include <stdio.h>

int	main()
{
	char	str[] = "   ---+-+ 12344857ab567";
 
	printf("%s\n", str);
	printf("%d\n", ft_atoi(str));
	return (0);
}
*/
