/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:08:43 by tayou             #+#    #+#             */
/*   Updated: 2023/04/22 22:10:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_moving_point(int to_x, int to_y, char to_point, t_data *game);

void	move_left(t_data *game)
{
	int		moving_point_x;
	int		moving_point_y;
	int		size;
	char	moving_point;

	size = game->block_size;
	moving_point_x = (game->player_x - 1) * size;
	moving_point_y = (game->player_y) * size;
	moving_point = game->array_map[moving_point_y][moving_point_x];
	move_to_moving_point(moving_point_x, moving_point_y, moving_point, game);
	game->player_x--;
}

void	move_right(t_data *game)
{
	int		moving_point_x;
	int		moving_point_y;
	int		size;
	char	moving_point;

	size = game->block_size;
	moving_point_x = (game->player_x + 1) * size;
	moving_point_y = (game->player_y) * size;
	moving_point = game->array_map[moving_point_y][moving_point_x];
	move_to_moving_point(moving_point_x, moving_point_y, moving_point, game);
	game->player_x++;
}

void	move_down(t_data *game)
{
	int		moving_point_x;
	int		moving_point_y;
	int		size;
	char	moving_point;

	size = game->block_size;
	moving_point_x = (game->player_x) * size;
	moving_point_y = (game->player_y - 1) * size;
	moving_point = game->array_map[moving_point_y][moving_point_x];
	move_to_moving_point(moving_point_x, moving_point_y, moving_point, game);
	game->player_y--;
}
void	move_up(t_data *game)
{
	int		moving_point_x;
	int		moving_point_y;
	int		size;
	char	moving_point;

	size = game->block_size;
	moving_point_x = (game->player_x) * size;
	moving_point_y = (game->player_y + 1) * size;
	moving_point = game->array_map[moving_point_y][moving_point_x];
	move_to_moving_point(moving_point_x, moving_point_y, moving_point, game);
	game->player_y++;
}

void	move_to_moving_point(int to_x, int to_y, char to_point, t_data *game)
{
	void	*mlx;
	void	*win;
	int		current_x;
	int		current_y;

	mlx = game->mlx_ptr;
	win = game->win_ptr;
	current_x = game->player_x * game->block_size;
	current_y = game->player_y * game->block_size;
	if (to_point == '0' || to_point == 'C')
	{
		mlx_put_image_to_window(mlx, win, game->empty, current_x, current_y);
		mlx_put_image_to_window(mlx, win, game->empty, to_x, to_y);
		mlx_put_image_to_window(mlx, win, game->player, to_x, to_y);
		if (to_point == 'C')
			game->collect_count++;
	}
	else if (to_point == 'E')
	{
		if (game->collect_count == game->collectible_count)
			end_game_after_free(game);
	}
}
