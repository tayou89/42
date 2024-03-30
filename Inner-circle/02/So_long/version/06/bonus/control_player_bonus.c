/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:30:50 by tayou             #+#    #+#             */
/*   Updated: 2023/04/26 13:05:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		key_press(int key_code, t_data *game);
void	make_exit_open(t_data *game);

void	control_player(t_data *game)
{
	mlx_hook(game->win_ptr, KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win_ptr, EVENT_ON_DESTROY, 0, &finish_game_after_free, game);
}

int	key_press(int key_code, t_data *game)
{
	game->current_x = game->player_x * game->block_size;
	game->current_y = game->player_y * game->block_size;
	if (key_code == KEY_A)
		move_left(game);
	else if (key_code == KEY_D)
		move_right(game);
	else if (key_code == KEY_S)
		move_down(game);
	else if (key_code == KEY_W)
		move_up(game);
	else if (key_code == KEY_ESC)
		finish_game_after_free(game);
	if (game->collect_count == game->collectible_count)
		make_exit_open(game);
	return (0);
}

void	make_exit_open(t_data *game)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = game->mlx_ptr;
	win = game->win_ptr;
	get_component_location('E', game);
	x = game->component_x * game->block_size;
	y = game->component_y * game->block_size;
	mlx_put_image_to_window(mlx, win, game->empty, x, y);
	mlx_put_image_to_window(mlx, win, game->done, x, y);
}