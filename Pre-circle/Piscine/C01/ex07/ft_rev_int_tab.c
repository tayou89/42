/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:05:55 by tayou             #+#    #+#             */
/*   Updated: 2022/10/07 00:51:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	n;

	n = size - 1;
	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[n - i];
		tab[n - i] = temp;
		i++;
	}
}
