/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujo <seujo@student.42seoul.k>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:17:51 by seujo             #+#    #+#             */
/*   Updated: 2022/10/02 18:13:44 by seujo            ###   ########.fr       */
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
			if ((l == 1 && w == 1) || (l == y && w == x && y != 1 && x != 1))
				ft_putchar('/');
			else if ((l == 1 && w == x) || (l == y && w == 1))
				ft_putchar('\\');
			else if (l > 1 && l < y && w > 1 && w < x)
				ft_putchar(' ');
			else
				ft_putchar('*');
			w++;
		}
		ft_putchar('\n');
		l++;
	}
}
