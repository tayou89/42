/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_surrounded_by_wall.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:35 by tayou             #+#    #+#             */
/*   Updated: 2023/05/08 11:56:17 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_first_line(char *first_line);
int		check_middle_line(char **map);
int		check_last_line(char **map);

int	check_map_surrounded_by_wall(t_data *game)
{
	char	**map;

	game->error_number = 2;
	map = game->map.array;
	if (check_first_line(map[0]) == FALSE
		|| check_middle_line(map) == FALSE
		|| check_last_line(map) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	check_first_line(char *first_line)
{
	int	i;

	if (first_line[0] == '\0')
		return (FALSE);
	i = 0;
	while (first_line[i] != '\0')
	{
		if (first_line[i] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_middle_line(char **map)
{
	char	first_character;
	char	last_character;
	int		i;

	i = 1;
	while (map[i + 1] != (void *) 0)
	{
		first_character = map[i][0];
		last_character = get_last_character(map[i]);
		if (first_character != '1' || last_character != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
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
			return (FALSE);
		i++;
	}
	return (TRUE);
}
