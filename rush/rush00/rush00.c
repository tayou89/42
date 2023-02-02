/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujo <seujo@student.42seoul.k>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:17:10 by seujo             #+#    #+#             */
/*   Updated: 2022/10/02 16:23:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	w;
	int	l;

	if (x <= 0 || y <= 0)
		return ;
	l = 1;
	while (l <= y)
	{
		w = 1;
		while (w <= x)
		{
			if ((l == 1 || l == y) && (w == 1 || w == x))
				ft_putchar('o');
			else if ((l == 1 || l == y) && (w > 1 && w < x))
				ft_putchar('-');
			else if (l > 1 && l < y && w > 1 && w < x)
				ft_putchar(' ');
			else
				ft_putchar('|');
			w++;
		}
		ft_putchar('\n');
		l++;
	}
}
