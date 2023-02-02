/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejikim <sejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:57:12 by sejikim           #+#    #+#             */
/*   Updated: 2022/10/09 23:03:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur(int x, int y, int n, char *argv);

int	cp(char *argv)
{
	int		argvi;
	int		idx;
	int		idy;
	char	arr[4][4];
	int		val;

	arr = {0, };
	val = 0;
	idy = 0;
	argvi = 0;
	while (idy < 4)
	{
		idx = 0;
		while (idx < 4)
		{
			if (argvi < 4 && argv[argvi] == '4')
			{
				while (val < 4)
				{
					arr[val][argvi % 4] = val + '1';
					val++;
				}
			}
			else if (argvi < 8 && argv[argvi] == '4')
			{
				while ((3 - val) >= 0)
				{
					arr[(3 - val)][argvi % 4] = (3 - val) + '1';
					val++;
				}
			}
			else if (argvi < 12 && argv[argvi] == '4')
			{
				while (val < 4)
				{
					arr[argvi % 4][val] = val + '1';
					val++;
				}
			}
			else if (argvi < 16 && argv[argvi] == '4')
			{
				while ((3 - val) >= 0)
				{
					arr[argvi % 4][(3 - val)] = (3 - val) + '1';
					val++;
				}
			}
			argvi++;
			idx++;
			val = 0;
		}
		idy++;
	}
}

void	split_char(char *str, char *arr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
			arr[j++] = str[i];
		i++;
	}
}

int	main(int ac, char **argv)
{
	char	arr[16];

	if (ac == 2)
	{
		split_char(argv[1], arr);
		cp(arr);
	}
	return (0);
}
