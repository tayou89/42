/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:09:30 by tayou             #+#    #+#             */
/*   Updated: 2023/05/10 20:52:58 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_xy_by_direction(int *x, int *y, int dir)
{
	if (dir == LEFT)
		(*x)--;
	else if (dir == RIGHT)
		(*x)++;
	else if (dir == DOWN)
		(*y)++;
	else if (dir == UP)
		(*y)--;
}

void	count_dir_image_number(int *number)
{
	if (*number == 3)
		*number = 0;
	else
		(*number)++;
}

void	get_enemy_target_location(t_data *game)
{
	game->enemy.target_x = game->enemy.map_x[game->enemy.witness];
	game->enemy.target_y = game->enemy.map_y[game->enemy.witness];
	count_xy_by_direction(&game->enemy.target_x, &game->enemy.target_y, \
			game->enemy.direction);
}

void	put_move_count_string(t_data *game)
{
	char	*move_count_string;

	move_count_string = ft_itoa(game->count.move);
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
		game->image.square_button, 0, 0);
	mlx_string_put(game->mlx.ptr, game->window.ptr, \
		(game->window.block_size / 2) - 5, (game->window.block_size / 2) + 4, \
		0, move_count_string);
	free(move_count_string);
	move_count_string = (void *) 0;
}
