/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_component_image_address.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:28:26 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 18:46:21 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_component_image_address(t_data *game)
{
	void	*mlx;
	int		size;

	mlx = game->mlx_ptr;
	size = game->block_size;
	game->empty = mlx_xpm_file_to_image(mlx, "./xpm/empty.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(mlx, "./xpm/wall.xpm", &size, &size);
	game->coll = mlx_xpm_file_to_image(mlx, "./xpm/coll.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(mlx, "./xpm/exit.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(mlx, "./xpm/player.xpm", &size, &size);
	game->done = mlx_xpm_file_to_image(mlx, "./xpm/done.xpm", &size, &size);
}
