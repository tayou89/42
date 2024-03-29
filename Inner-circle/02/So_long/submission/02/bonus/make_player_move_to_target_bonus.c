/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_player_move_to_target_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:30:29 by tayou             #+#    #+#             */
/*   Updated: 2023/05/07 14:27:12 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	make_turn_to_direction(t_data *game);
static void	move_one_step_to_target(int *k, t_data *game);
static void	get_next_player_window_xy(int step_width, t_data *game);
static void	set_data_and_print_step(int *k, t_data *game);

void	make_player_move_to_target(t_data *game)
{
	static int	k;

	if (k == 0)
		make_turn_to_direction(game);
	if (k == 500)
		move_one_step_to_target(&k, game);
	if (k > 500)
		set_data_and_print_step(&k, game);
	k++;
}

static void	make_turn_to_direction(t_data *game)
{
	game->player.window_x = game->player.map_x * game->window.block_size;
	game->player.window_y = game->player.map_y * game->window.block_size;
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
			game->image.empty, game->player.window_x, game->player.window_y);
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
			game->image.player[game->player.direction][0], \
			game->player.window_x, game->player.window_y);
	game->image.player_number = 0;
}

static void	move_one_step_to_target(int *k, t_data *game)
{
	int	dir;

	dir = game->player.direction;
	count_dir_image_number(&game->image.player_number);
	get_next_player_window_xy(game->window.block_size / 4, game);
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
			game->image.empty, game->player.map_x * game->window.block_size, \
			game->player.map_y * game->window.block_size);
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
			game->image.empty, \
			game->player.target_x * game->window.block_size, \
			game->player.target_y * game->window.block_size);
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
			game->image.player[dir][game->image.player_number], \
			game->player.window_x, game->player.window_y);
	if (game->player.window_x != \
			game->player.target_x * game->window.block_size
		|| game->player.window_y != \
			game->player.target_y * game->window.block_size)
		*k = 1;
}

static void	get_next_player_window_xy(int step_width, t_data *game)
{
	int	i;

	i = 0;
	while (i < step_width)
	{
		count_xy_by_direction(&game->player.window_x, \
				&game->player.window_y, game->player.direction);
		i++;
	}
}

static void	set_data_and_print_step(int *k, t_data *game)
{
	game->count.move++;
	put_move_count_string(game);
	game->map.array[game->player.target_y][game->player.target_x] = \
		game->component.empty_space;
	game->player.map_x = game->player.target_x;
	game->player.map_y = game->player.target_y;
	game->flag.player_move = FALSE;
	game->flag.player_move_complete = TRUE;
	if (game->component.target == game->component.collectible)
		game->count.collect++;
	*k = 0;
}
