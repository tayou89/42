/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:41:11 by tayou             #+#    #+#             */
/*   Updated: 2022/10/15 23:40:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	divisor;

	divisor = 2;
	while (divisor <= nb / divisor)
	{
		if (nb % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	else if (ft_is_prime(nb) == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
/*
#include <stdio.h>

int	main()
{
	int	nb;

	printf("nb : ");
	scanf("%d", &nb);
	printf("return : %d\n", ft_find_next_prime(nb));
	return (0);
}
*/
