/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_surrounded_by_wall.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:34 by tayou             #+#    #+#             */
/*   Updated: 2023/04/12 15:11:39 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_first_line(char *first_line);
int		check_middle_line(char **map);
int		check_last_line(char **map);

int	check_map_surrounded_by_wall(char **map)
{
	if (check_first_line(map[0]) == 1 || check_middle_line(map) == 1
		|| check_last_line(map) == 1)
		return (1);
	return (0);
}

int	check_first_line(char *first_line)
{
	int	i;

	i = 0;
	while (first_line[i] != '\0')
	{
		if (first_line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_middle_line(char **map)
{
	char	first_character;
	char	last_character;
	int	i;

	i = 1;
	while (map[i + 1] != (void *) 0)
	{
		first_character = map[i][0];
		last_character = get_last_character(map[i]);
		if (first_character != '1' || last_character != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_last_line(char **map)
{
	char	*last_line;
	int		i;

	last_line = get_last_line(map);
	i = 0;
	while (last_line[i] != '\0')
	{
		if (last_line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
