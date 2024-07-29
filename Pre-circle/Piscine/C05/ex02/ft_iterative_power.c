/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:30:08 by tayou             #+#    #+#             */
/*   Updated: 2022/10/15 22:40:08 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	number;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	number = 1;
	while (power > 0)
	{
		number *= nb;
		power--;
	}
	return (number);
}
/*
#include <stdio.h>

int	main()
{
	int	nb;
	int	power;

	printf("nb : ");
	scanf("%d", &nb);
	printf("power : ");
	scanf("%d", &power);
	printf("%d\n", ft_iterative_power(nb, power));
	return (0);
}
*/
