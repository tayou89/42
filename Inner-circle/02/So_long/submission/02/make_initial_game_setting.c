/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_initial_game_setting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:49:56 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 18:34:33 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->flag.movible = FALSE;
	get_component_location(game->component.player, game);
	game->player.map_x = game->component.map_x;
	game->player.map_y = game->component.map_y;
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
	if (component == game->component.wall)
		mlx_put_image_to_window(mlx, win, game->image.wall, x, y);
	else if (component == game->component.collectible)
		mlx_put_image_to_window(mlx, win, game->image.collectible, x, y);
	else if (component == game->component.exit)
		mlx_put_image_to_window(mlx, win, game->image.exit, x, y);
	else if (component == game->component.player)
		mlx_put_image_to_window(mlx, win, game->image.player, x, y);
}
