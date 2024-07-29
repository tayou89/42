/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:03:51 by tayou             #+#    #+#             */
/*   Updated: 2022/10/07 21:14:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_numbersign(int *quotient)
{
	if (*quotient == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		*quotient = 147483648;
	}	
	if (*quotient < 0)
	{
		*quotient *= (-1);
		write(1, "-", 1);
	}
}

void	find_digit(int quotient, int remainder, int *count, char *digit)
{	
	*count = 0;
	if (quotient == 0)
		digit[*count] = quotient + '0';
	while (quotient > 0)
	{
		remainder = quotient % 10;
		digit[*count] = remainder + '0';
		(*count)++;
		quotient /= 10;
	}
}

void	print_digit(int count, char *digit)
{	
	int	i;

	if (count == 0)
		write(1, &digit[0], 1);
	i = count - 1;
	while (i >= 0)
	{
		write(1, &digit[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int		quotient;
	int		remainder;
	int		count;
	char	digit[10];

	quotient = nb;
	remainder = 0;
	check_numbersign(&quotient);
	find_digit(quotient, remainder, &count, digit);
	print_digit(count, digit);
}
/*
int main()
{
	ft_putnbr(0);
	return 0;
}
*/
