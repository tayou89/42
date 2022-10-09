/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:06:52 by tayou             #+#    #+#             */
/*   Updated: 2022/10/07 00:36:11 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	digit[3];

	digit[0] = '0';
	while (digit[0] <= '7')
	{
		digit[1] = digit[0] + 1;
		while (digit[1] <= '8')
		{
			digit[2] = digit[1] + 1;
			while (digit[2] <= '9')
			{
				write(1, digit, 3);
				if (digit[0] == '7' && digit[1] == '8' && digit[2])
					return ;
				write(1, ", ", 2);
				digit[2]++;
			}
			digit[1]++;
		}
		digit[0]++;
	}
}
/*
int main()
{
	ft_print_comb();

	return 0;
}
*/
