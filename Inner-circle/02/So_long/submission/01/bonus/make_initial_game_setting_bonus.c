/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_initial_game_setting_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:32:57 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 18:38:19 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initial_game_data_setting(t_data *game);
void	open_window(t_data *game);
void	draw_map(t_data *game);
void	apply_component_image(char component, int i, int j, t_data *game);

void	make_initial_game_setting(t_data *game)
{
	initial_game_data_setting(game);
	open_window(game);
	get_image_address(game);
	draw_map(game);
	game->map.array[game->player.map_y][game->player.map_x] \
		= game->component.empty_space;
}

void	initial_game_data_setting(t_data *game)
{
	game->window.block_size = 64;
	game->count.move = 0;
	game->count.collect = 0;
	game->enemy.direction = DOWN;
	game->flag.player_move_complete = 1;
	game->flag.enemy_move = 0;
	game->flag.exit_open = 'X';
	game->flag.find_invader = 0;
	get_player_location(game);
	get_enemy_location(game);
}

void	open_window(t_data *game)
{
	game->mlx.ptr = mlx_init();
	game->window.x_size \
		= ft_strlen(game->map.array[0]) * game->window.block_size;
	game->window.y_size = game->map.line_count * game->window.block_size;
	game->window.ptr = mlx_new_window(game->mlx.ptr, \
		game->window.x_size, game->window.y_size, "so_long");
}

void	draw_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i] != (void *) 0)
	{
		j = 0;
		while (game->map.array[i][j] != '\0')
		{
			apply_component_image(game->map.array[i][j], i, j, game);
			j++;
		}
		i++;
	}
	put_move_count_string(game);
}

void	apply_component_image(char component, int i, int j, t_data *game)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = game->mlx.ptr;
	win = game->window.ptr;
	x = j * game->window.block_size;
	y = i * game->window.block_size;
	mlx_put_image_to_window(mlx, win, game->image.empty, x, y);
	if (x == 0 && y == 0)
		mlx_put_image_to_window(mlx, win, game->image.square_button, x, y);
	else if (component == game->component.wall)
		mlx_put_image_to_window(mlx, win, game->image.wall, x, y);
	else if (component == game->component.collectible)
		mlx_put_image_to_window(mlx, win, game->image.collectible, x, y);
	else if (component == game->component.exit)
		mlx_put_image_to_window(mlx, win, game->image.exit, x, y);
	else if (component == game->component.player)
		mlx_put_image_to_window(mlx, win, game->image.player[DOWN][0], x, y);
	else if (component == game->component.enemy)
		mlx_put_image_to_window(mlx, win, game->image.enemy[DOWN][0], x, y);
}
