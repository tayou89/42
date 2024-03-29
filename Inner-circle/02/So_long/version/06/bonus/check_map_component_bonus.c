/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_component_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:28:54 by tayou             #+#    #+#             */
/*   Updated: 2023/04/26 12:46:42 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_component_count(t_data *game);
void	get_component_count(t_data *game);
int		check_if_has_other_character(char **map);

int	check_map_component(char **map, t_data *game)
{
	initialize_component_count(game);
	get_component_count(game);
	if (game->exit_count != 1 || game->collectible_count < 1
		|| game->player_count != 1 || game->enemy_count < 1)
		return (1);
	if (check_if_has_other_character(map) == 1)
		return (1);
	return (0);
}

void	initialize_component_count(t_data *game)
{
	game->exit_count = 0;
	game->collectible_count = 0;
	game->player_count = 0;
	game->enemy_count = 0;
}

void	get_component_count(t_data *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->array_map;
	i = 0;
	while (map[i] != (void *) 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				game->exit_count++;
			else if (map[i][j] == 'C')
				game->collectible_count++;
			else if (map[i][j] == 'P')
				game->player_count++;
			else if (map[i][j] == 'B')
				game->enemy_count++;
			j++;
		}
		i++;
	}
}

int	check_if_has_other_character(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i] != (void *) 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C'
				|| map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == 'B')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
