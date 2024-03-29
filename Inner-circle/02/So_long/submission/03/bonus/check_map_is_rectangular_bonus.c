/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_rectangular_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:29:47 by tayou             #+#    #+#             */
/*   Updated: 2023/05/14 19:02:04 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map_is_rectangular(t_data *game)
{
	char	**map;
	int		first_line_size;
	int		next_line_size;
	int		i;

	game->error_number = 1;
	map = game->map.array;
	if (map == (void *) 0)
		return (FALSE);
	first_line_size = ft_strlen(map[0]);
	i = 1;
	while (map[i] != (void *) 0)
	{
		next_line_size = ft_strlen(map[i]);
		if (first_line_size != next_line_size)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
