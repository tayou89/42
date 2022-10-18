/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:39:52 by tayou             #+#    #+#             */
/*   Updated: 2022/10/16 20:35:33 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
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
	printf("%d\n", ft_recursive_power(nb, power));
	return (0);
}
*/
