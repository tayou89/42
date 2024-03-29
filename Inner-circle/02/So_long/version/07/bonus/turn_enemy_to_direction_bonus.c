/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_enemy_to_direction_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:55:53 by tayou             #+#    #+#             */
/*   Updated: 2023/05/06 13:25:51 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	turn_every_enemy_to_direction(t_data *game);
static void	erase_enemy_character(int i, t_data *game);
static void	put_enemy_turned_image_by_direction(int i, t_data *game);

void	turn_enemy_to_direction(t_data *game)
{
	if (game->flag.find_invader == TRUE)
		return ;
	count_dir_image_number(&game->enemy.direction);
	turn_every_enemy_to_direction(game);
}

static void	turn_every_enemy_to_direction(t_data *game)
{
	int	i;

	game->image.enemy_number = 0;
	i = 0;
	while (i < game->count.enemy)
	{
		erase_enemy_character(i, game);
		put_enemy_turned_image_by_direction(i, game);
		i++;
	}
}

static void	erase_enemy_character(int i, t_data *game)
{
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
		game->image.empty, game->enemy.map_x[i] * game->window.block_size, \
		game->enemy.map_y[i] * game->window.block_size);
}

static void	put_enemy_turned_image_by_direction(int i, t_data *game)
{
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
		game->image.enemy[game->enemy.direction][game->image.enemy_number], \
		game->enemy.map_x[i] * game->window.block_size, \
		game->enemy.map_y[i] * game->window.block_size);
}
