/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_player_move_to_target.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:17:03 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 14:26:38 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	erase_player_on_window(t_data *game);
void	put_player_image_on_target(t_data *game);
void	set_data_and_print_step(t_data *game);

void	make_player_move_to_target(t_data *game)
{
	erase_player_on_window(game);
	put_player_image_on_target(game);
	set_data_and_print_step(game);
}

void	erase_player_on_window(t_data *game)
{
	void	*mlx;
	void	*win;
	int		size;

	mlx = game->mlx.ptr;
	win = game->window.ptr;
	size = game->window.block_size;
	mlx_put_image_to_window(mlx, win, game->image.empty, \
		game->player.map_x * size, game->player.map_y * size);
	mlx_put_image_to_window(mlx, win, game->image.empty, \
		game->player.target_x * size, game->player.target_y * size);
}

void	put_player_image_on_target(t_data *game)
{
	mlx_put_image_to_window(game->mlx.ptr, game->window.ptr, \
		game->image.player, game->player.target_x * game->window.block_size, \
		game->player.target_y * game->window.block_size);
}

void	set_data_and_print_step(t_data *game)
{
	game->count.move++;
	ft_printf("Step: %d\n", game->count.move);
	game->map.array[game->player.target_y][game->player.target_x] = \
		game->component.empty_space;
	game->player.map_x = game->player.target_x;
	game->player.map_y = game->player.target_y;
	game->flag.movible = FALSE;
	if (game->component.target == game->component.collectible)
		game->count.collect++;
}
