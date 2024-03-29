/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:33:50 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 22:33:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	apply_component_image(char component, int i, int j, t_data *game);

void	put_image_to_map(t_data *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->array_map;
	i = 0;
	while (map[i] != (void *) 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			apply_component_image(map[i][j], i , j, game);
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

	mlx = game->m;
	win = game->w;
	x = j * game->block_size;
	y = i * game->block_size;
	mlx_put_image_to_window(mlx, win, game->empty, x, y);
	if (component == '1')
		mlx_put_image_to_window(mlx, win, game->wall, x, y);
	else if (component == 'C')
		mlx_put_image_to_window(mlx, win, game->coll, x, y);
	else if (component == 'E')
		mlx_put_image_to_window(mlx, win, game->exit, x, y);
	else if (component == 'P')
		mlx_put_image_to_window(mlx, win, game->player, x, y);
}
