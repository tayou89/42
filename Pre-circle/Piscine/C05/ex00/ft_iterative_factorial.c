/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:36:34 by tayou             #+#    #+#             */
/*   Updated: 2022/10/15 22:17:01 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	number;

	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	number = 1;
	while (nb > 0)
	{
		number *= nb;
		nb--;
	}
	return (number);
}
/*
#include <stdio.h>

int	main()
{
	int	nb;

	printf("input : ");
	scanf("%d", &nb);
	printf("%d\n", ft_iterative_factorial(nb));
	return (0);
}
*/
