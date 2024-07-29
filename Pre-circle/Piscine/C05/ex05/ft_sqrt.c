/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:33:07 by tayou             #+#    #+#             */
/*   Updated: 2022/10/15 22:37:13 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb == 0)
		return (0);
	sqrt = 1;
	while (sqrt <= nb / sqrt)
	{
		if (sqrt == nb / sqrt && nb % sqrt == 0)
			return (sqrt);
		else
			sqrt++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	int	nb;

	printf("nb : ");
	scanf("%d", &nb);
	printf("제곱근 : %d\n", ft_sqrt(nb));
	return (0);
}
*/
