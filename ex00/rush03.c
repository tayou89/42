/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujo <seujo@student.42seoul.k>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:21:11 by seujo             #+#    #+#             */
/*   Updated: 2022/10/02 12:21:52 by seujo            ###   ########.fr       */
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
			if (w == 1 && (l == 1 || l == y))
				ft_putchar('A');
			else if (w == x && (l == 1 || l == y))
				ft_putchar('C');
			else if (l > 1 && l < y && w > 1 && w < x)
				ft_putchar(' ');
			else
				ft_putchar('B');
			w++;
		}
		ft_putchar('\n');
		l++;
	}
}
