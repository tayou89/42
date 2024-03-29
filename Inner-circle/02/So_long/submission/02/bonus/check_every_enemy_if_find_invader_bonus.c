/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_every_enemy_if_find_invader_bonus.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:32:42 by tayou             #+#    #+#             */
/*   Updated: 2023/05/07 19:30:28 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_invader_on_sight(int i, t_data *game);
void	change_enemy_data_to_move(int i, t_data *game);

void	check_every_enemy_if_find_invader(int *k, t_data *game)
{
	int	i;

	if (game->flag.find_invader == TRUE)
		return ;
	i = 0;
	while (i < game->count.enemy)
	{
		check_invader_on_sight(i, game);
		if (game->flag.find_invader == TRUE)
		{
			change_enemy_data_to_move(i, game);
			return ;
		}
		i++;
	}
	if (*k == 19999)
		*k = 0;
}

void	check_invader_on_sight(int i, t_data *game)
{
	char	**map;
	int		enemy_y;
	int		enemy_x;

	map = game->map.array;
	enemy_y = game->enemy.map_y[i];
	enemy_x = game->enemy.map_x[i];
	while (map[enemy_y][enemy_x] == game->component.empty_space
			|| map[enemy_y][enemy_x] == game->component.enemy
			|| map[enemy_y][enemy_x] == game->component.collectible)
	{
		if (enemy_x == game->player.map_x && enemy_y == game->player.map_y)
		{
			game->flag.find_invader = TRUE;
			return ;
		}
		count_xy_by_direction(&enemy_x, &enemy_y, game->enemy.direction);
	}
}

void	change_enemy_data_to_move(int i, t_data *game)
{
	game->enemy.witness = i;
	game->enemy.window_x = game->enemy.map_x[i] * game->window.block_size;
	game->enemy.window_y = game->enemy.map_y[i] * game->window.block_size;
	game->flag.enemy_move = TRUE;
}
