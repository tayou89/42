/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_component.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:44:00 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 15:33:35 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_image_when_moving_point_is_0(int x, int y, t_data *game);
int	set_image_when_moving_point_is_c(int x, int y, t_data *game);
int	set_image_when_moving_point_is_e(int x, int y, t_data *game);

int	move_by_component(int x, int y, char component, t_data *game)
{
	int	move_sign;

	move_sign = 0;
	if (component == '0')
		move_sign = set_image_when_moving_point_is_0(x, y, game);
	else if (component == 'C')
	{
		move_sign = set_image_when_moving_point_is_c(x, y, game);
		game->array_map[y / game->block_size][x / game->block_size] = '0';
		game->collect_count++;
	}
	else if (component == 'E')
		move_sign = set_image_when_moving_point_is_e(x, y, game);
	return (move_sign);
}

int	set_image_when_moving_point_is_0(int x, int y, t_data *game)
{
	void	*mlx;
	void	*win;
	int		current_x;
	int		current_y;
	int		move_sign;

	mlx = game->mlx_ptr;
	win = game->win_ptr;
	current_x = game->player_x * game->block_size;
	current_y = game->player_y * game->block_size;
	mlx_put_image_to_window(mlx, win, game->empty, current_x, current_y);
	mlx_put_image_to_window(mlx, win, game->player, x, y);
	move_sign = 1;
	return (move_sign);
}

int	set_image_when_moving_point_is_c(int x, int y, t_data *game)
{
	void	*mlx;
	void	*win;
	int		current_x;
	int		current_y;
	int		move_sign;

	mlx = game->mlx_ptr;
	win = game->win_ptr;
	current_x = game->player_x * game->block_size;
	current_y = game->player_y * game->block_size;
	mlx_put_image_to_window(mlx, win, game->empty, current_x, current_y);
	mlx_put_image_to_window(mlx, win, game->empty, x, y);
	mlx_put_image_to_window(mlx, win, game->player, x, y);
	move_sign = 1;
	return (move_sign);
}

int	set_image_when_moving_point_is_e(int x, int y, t_data *game)
{
	void	*mlx;
	void	*win;
	int		current_x;
	int		current_y;
	int		move_sign;

	mlx = game->mlx_ptr;
	win = game->win_ptr;
	current_x = game->player_x * game->block_size;
	current_y = game->player_y * game->block_size;
	move_sign = 0;
	if (game->collect_count == game->collectible_count)
	{
		mlx_put_image_to_window(mlx, win, game->empty, current_x, current_y);
		mlx_put_image_to_window(mlx, win, game->player, x, y);
		move_sign = 1;
		finish_game_after_free(game);
	}
	return (move_sign);
}
