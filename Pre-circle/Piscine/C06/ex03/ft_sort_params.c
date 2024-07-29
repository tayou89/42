/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:54:40 by tayou             #+#    #+#             */
/*   Updated: 2022/10/16 23:58:31 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	arrange_argv(int *argc, char *argv[])
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	i = 1;
	while (i < *argc - 1)
	{
		j = i + 1;
		while (j < *argc)
		{
			k = 0;
			while (argv[i][k] == argv[j][k])
				k++;
			if (argv[i][k] > argv[j][k])
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;

	arrange_argv(&argc, argv);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
