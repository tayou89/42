/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx_win_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:03:16 by tayou             #+#    #+#             */
/*   Updated: 2023/04/21 23:53:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_window_size(t_data *game);
int		get_win_x_size(char **map, int block_size);
int		get_win_y_size(int map_line_count, int block_size);

void	get_mlx_win_ptr(t_data *game)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_x_size;
	int		win_y_size;

	mlx_ptr = mlx_init();
	game->mlx_ptr = mlx_ptr;
	get_window_size(game);
	win_x_size = game->win_x_size;
	win_y_size = game->win_y_size;
	win_ptr = mlx_new_window(mlx_ptr, win_x_size, win_y_size, "so_long");
	game->win_ptr = win_ptr;
}

void	get_window_size(t_data *game)
{
	char	**map;
	int		win_x_size;
	int		win_y_size;

	map = game->array_map;
	win_x_size = get_win_x_size(map, game->block_size);
	win_y_size = get_win_y_size(game->map_line_count, game->block_size);
	game->win_x_size = win_x_size;
	game->win_y_size = win_y_size;
}

int	get_win_x_size(char **map, int block_size)
{
	int	win_x_size;
	int	character_in_one_line;

	character_in_one_line = ft_strlen(map[0]);
	win_x_size = character_in_one_line * block_size;
	return (win_x_size);
}

int	get_win_y_size(int map_line_count, int block_size)
{
	int	win_y_size;

	win_y_size = map_line_count * block_size;
	return (win_y_size);
}
