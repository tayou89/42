/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_rectangular_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:29:47 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 11:07:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map_is_rectangular(t_data *game)
{
	char	**map;
	int		first_line_size;
	int		next_line_size;
	int		i;

	map = game->map.array;
	first_line_size = ft_strlen(map[0]);
	if (first_line_size == 0)
		return (FALSE);
	i = 0;
	while (map[i] != (void *) 0)
	{
		next_line_size = ft_strlen(map[i]);
		if (first_line_size != next_line_size)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
