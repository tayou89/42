/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_enemy_location.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:36:14 by tayou             #+#    #+#             */
/*   Updated: 2023/04/26 12:40:25 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	malloc_enemy_location(t_data *game);

void	get_player_location(t_data *game)
{
	get_component_location('P', game);
	game->player_x = game->component_x;
	game->player_y = game->component_y;
}

void	get_enemy_location(t_data *game)
{
	char	**map;
	int		i;
	int		j;
	int		k;

	map = game->array_map;
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
				game->enemy_x[k] = j;
				game->enemy_y[k] = i;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	malloc_enemy_location(t_data *game)
{
	game->enemy_x = (int *) malloc(sizeof(int) * game->enemy_count);
	game->enemy_y = (int *) malloc(sizeof(int) * game->enemy_count);
	if (game->enemy_x == (void *) 0 || game->enemy_y == (void *) 0)
	{
		free_mallocated_data(game);
		exit(1);
	}
}
