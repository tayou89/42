/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_rectangular.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:13:16 by tayou             #+#    #+#             */
/*   Updated: 2023/04/14 22:29:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_is_rectangular(char **map)
{
	int	first_line_size;
	int	next_line_size;
	int	i;

	first_line_size = ft_strlen(map[0]);
	if (first_line_size == 0)
		return (1);
	i = 0;
	while (map[i] != (void *) 0)
	{
		next_line_size = ft_strlen(map[i]);
		if (first_line_size != next_line_size)
			return (1);
		i++;
	}
	return (0);
}
