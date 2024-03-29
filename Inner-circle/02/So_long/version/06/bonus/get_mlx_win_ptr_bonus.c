/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx_win_ptr_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:32:27 by tayou             #+#    #+#             */
/*   Updated: 2023/04/27 15:34:08 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_window_size(t_data *game);
int		get_win_x_size(char **map, int block_size);
int		get_win_y_size(int map_line_count, int block_size);

void	get_mlx_win_ptr(t_data *game)
{
	int		win_x_size;
	int		win_y_size;

	game->mlx_ptr = mlx_init();
	get_window_size(game);
	win_x_size = game->win_x_size;
	win_y_size = game->win_y_size;
	game->win_ptr = mlx_new_window(\
			game->mlx_ptr, win_x_size, win_y_size, "so_long");
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
