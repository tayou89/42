/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:51:55 by tayou             #+#    #+#             */
/*   Updated: 2022/10/16 17:00:24 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	divisor;

	if (nb <= 1)
		return (0);
	divisor = 2;
	while (divisor <= nb / divisor)
	{
		if (nb % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main()
{
	int	nb;

	printf("nb : ");
	scanf("%d", &nb);
	printf("반환값 : %d\n", ft_is_prime(nb));
	return (0);
}
*/
