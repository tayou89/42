/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_to_direction_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:53:19 by tayou             #+#    #+#             */
/*   Updated: 2023/05/07 19:30:00 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	erase_enemy_image(t_data *game);
void	get_next_enemy_window_xy(t_data *game);
void	put_enemy_image_to_window_xy(t_data *game);
void	check_arrive_to_target(t_data *game);

void	move_enemy_to_direction(int *k, t_data *game)
{
	get_enemy_target_location(game);
	if (game->enemy.target_x == game->player.map_x
		&& game->enemy.target_y == game->player.map_y)
		return ;
	count_dir_image_number(&game->image.enemy_number);
	erase_enemy_image(game);
	get_next_enemy_window_xy(game);
	put_enemy_image_to_window_xy(game);
	check_arrive_to_target(game);
	*k = 19500;
}

void	erase_enemy_image(t_data *game)
{
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
			game->image.empty, \
			game->enemy.map_x[game->enemy.witness] * game->window.block_size, \
			game->enemy.map_y[game->enemy.witness] * game->window.block_size);
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
			game->image.empty, \
			game->enemy.target_x * game->window.block_size, \
			game->enemy.target_y * game->window.block_size);
}

void	get_next_enemy_window_xy(t_data *game)
{
	int	i;

	i = 0;
	while (i < (game->window.block_size / 4))
	{
		count_xy_by_direction(&game->enemy.window_x, &game->enemy.window_y, \
				game->enemy.direction);
		i++;
	}
}

void	put_enemy_image_to_window_xy(t_data *game)
{
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
		game->image.enemy[game->enemy.direction][game->image.enemy_number], \
		game->enemy.window_x, game->enemy.window_y);
}

void	check_arrive_to_target(t_data *game)
{
	int	size;

	size = game->window.block_size;
	if (game->enemy.window_x == game->enemy.target_x * size
		&& game->enemy.window_y == game->enemy.target_y * size)
		count_xy_by_direction(&game->enemy.map_x[game->enemy.witness], \
			&game->enemy.map_y[game->enemy.witness], game->enemy.direction);
}
