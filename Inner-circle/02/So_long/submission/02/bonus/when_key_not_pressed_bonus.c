/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_key_not_pressed_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:48:12 by tayou             #+#    #+#             */
/*   Updated: 2023/05/07 19:53:32 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		functions_when_key_not_pressed(t_data *game);
void	get_target_component(t_data *game);
void	move_by_target_component(t_data *game);
void	make_exit_open(t_data *game);

void	when_key_not_pressed(t_data *game)
{
	mlx_loop_hook(game->mlx.ptr, &functions_when_key_not_pressed, game);
	mlx_loop(game->mlx.ptr);
}

int	functions_when_key_not_pressed(t_data *game)
{
	make_enemy_on_guard(game);
	if (game->flag.player_move == TRUE && game->flag.find_invader == FALSE)
	{
		get_target_component(game);
		move_by_target_component(game);
	}
	if ((game->count.collect == game->count.collectible)
		&& game->flag.exit_open == 'X')
		make_exit_open(game);
	return (0);
}

void	get_target_component(t_data *game)
{
	game->player.target_x = game->player.map_x;
	game->player.target_y = game->player.map_y;
	count_xy_by_direction(&game->player.target_x, &game->player.target_y, \
			game->player.direction);
	game->component.target = \
		game->map.array[game->player.target_y][game->player.target_x];
}

void	move_by_target_component(t_data *game)
{
	if (game->component.target == game->component.empty_space
		|| game->component.target == game->component.collectible)
		make_player_move_to_target(game);
	else if (game->component.target == game->component.exit)
	{
		if (game->count.collect == game->count.collectible)
		{
			finish_game_after_free(game);
			exit(0);
		}
	}
	else
	{
		game->flag.player_move = FALSE;
		game->flag.player_move_complete = TRUE;
	}
}

void	make_exit_open(t_data *game)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = game->mlx.ptr;
	win = game->window.ptr;
	get_component_location(game->component.exit, game);
	x = game->component.map_x * game->window.block_size;
	y = game->component.map_y * game->window.block_size;
	mlx_put_image_to_window(mlx, win, game->image.empty, x, y);
	mlx_put_image_to_window(mlx, win, game->image.done, x, y);
	game->flag.exit_open = 'O';
}
