/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:47:30 by tayou             #+#    #+#             */
/*   Updated: 2022/10/07 21:19:27 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill_digit(int a, int b, char *digit)
{
	digit[0] = a / 10 + '0';
	digit[1] = a % 10 + '0';
	digit[2] = ' ';
	digit[3] = b / 10 + '0';
	digit[4] = b % 10 + '0';
	digit[5] = ',';
	digit[6] = ' ';
}

void	print(int a, char *digit)
{	
	if (a < 98)
	{
		write(1, digit, 7);
	}
	else if (a == 98)
	{
		write(1, digit, 5);
	}
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	char	digit[7];

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			fill_digit(a, b, digit);
			print(a, digit);
			b++;
		}		
		a++;
	}
}
/*
int main()
{
	ft_print_comb2();

	return 0;
}
*/
