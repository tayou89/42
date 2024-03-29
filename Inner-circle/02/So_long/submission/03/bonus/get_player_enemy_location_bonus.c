/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_enemy_location_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:36:14 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 12:01:48 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	malloc_enemy_location(t_data *game);

void	get_player_location(t_data *game)
{
	get_component_location(game->component.player, game);
	game->player.map_x = game->component.map_x;
	game->player.map_y = game->component.map_y;
}

void	get_enemy_location(t_data *game)
{
	char	**map;
	int		i;
	int		j;
	int		k;

	map = game->map.array;
	malloc_enemy_location(game);
	k = 0;
	i = 0;
	while (map[i] != (void *) 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'B')
			{
				game->enemy.map_x[k] = j;
				game->enemy.map_y[k] = i;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	malloc_enemy_location(t_data *game)
{
	game->enemy.map_x = (int *) malloc(sizeof(int) * game->count.enemy);
	game->enemy.map_y = (int *) malloc(sizeof(int) * game->count.enemy);
	if (game->enemy.map_x == (void *) 0 || game->enemy.map_y == (void *) 0)
	{
		free_mallocated_data(game);
		exit(1);
	}
}
