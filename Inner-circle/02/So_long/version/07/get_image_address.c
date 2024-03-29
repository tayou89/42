/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:53:17 by tayou             #+#    #+#             */
/*   Updated: 2023/05/07 14:05:48 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_xpm(char *file_path, t_data *game);

void	get_image_address(t_data *game)
{
	game->image.empty = get_xpm("./textures/empty.xpm", game);
	game->image.wall = get_xpm("./textures/wall.xpm", game);
	game->image.collectible = get_xpm("./textures/coll.xpm", game);
	game->image.exit = get_xpm("./textures/exit.xpm", game);
	game->image.done = get_xpm("./textures/done.xpm", game);
	game->image.player = get_xpm("./textures/player.xpm", game);
}

void	*get_xpm(char *file_path, t_data *game)
{
	void	*image;

	image = mlx_xpm_file_to_image(game->mlx.ptr, file_path, \
			&game->window.block_size, &game->window.block_size);
	return (image);
}
