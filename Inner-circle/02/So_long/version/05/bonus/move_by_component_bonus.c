/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_component_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:33:24 by tayou             #+#    #+#             */
/*   Updated: 2023/04/24 12:22:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		set_image_when_moving_point_is_0(int x, int y, t_image *image, t_data *game);
int		set_image_when_moving_point_is_c(int x, int y, t_image *image, t_data *game);
int		set_image_when_moving_point_is_e(int x, int y, t_image *image, t_data *game);
void	show_sprite_image(int *cx, int *cy, t_image *image, t_data *game);

int	move_by_component(int x, int y, t_image *image, t_data *game)
{
	char	component;
	int		move_sign;

	move_sign = 0;
	component = game->array_map[y / game->block_size][x / game->block_size];
	if (component == '0')
		move_sign = set_image_when_moving_point_is_0(x, y, image, game);
	else if (component == 'C')
	{
		move_sign = set_image_when_moving_point_is_c(x, y, image, game);
		game->array_map[y / game->block_size][x / game->block_size] = '0';
		game->collect_count++;
	}
	else if (component == 'E')
		move_sign = set_image_when_moving_point_is_e(x, y, image, game);
	return (move_sign);
}

int	set_image_when_moving_point_is_0(int x, int y, t_image *image, t_data *game)
{
	int		cx;
	int		cy;
	int		tx;
	int		ty;

	cx = game->player_x * game->block_size;
	cy = game->player_y * game->block_size;
	tx = 0;
	ty = 0;
	if (x - cx != 0)
		tx = ((x - cx) / abs(x - cx)) * 8;
	if (y - cy != 0)
		ty = ((y - cy) / abs(y - cy)) * 8;
	show_sprite_image(&cx, &cy, image, game);
	mlx_put_image_to_window(game->m, game->w, game->empty, cx, cy);
	mlx_put_image_to_window(game->m, game->w, image[0].image, cx + tx, cy + ty);
	return (1);
}

int	set_image_when_moving_point_is_c(int x, int y, t_image *image, t_data *game)
{
	int	cx;
	int	cy;
	int	tx;
	int	ty;

	cx = game->player_x * game->block_size;
	cy = game->player_y * game->block_size;
	tx = 0;
	ty = 0;
	if (x - cx != 0)
		tx = ((x - cx) / abs(x - cx)) * 8;
	if (y - cy != 0)
		ty = ((y - cy) / abs(y - cy)) * 8;
	show_sprite_image(&cx, &cy, image, game);
	mlx_put_image_to_window(game->m, game->w, game->empty, cx, cy);
	mlx_put_image_to_window(game->m, game->w, game->empty, cx + tx, cy + ty);
	mlx_put_image_to_window(game->m, game->w, image[0].image, cx + tx, cy + ty);
	return (1);
}

int	set_image_when_moving_point_is_e(int x, int y, t_image *image, t_data *game)
{
	int	cx;
	int	cy;
	int	tx;
	int	ty;

	cx = game->player_x * game->block_size;
	cy = game->player_y * game->block_size;
	tx = 0;
	ty = 0;
	if (x - cx != 0)
		tx = ((x - cx) / abs(x - cx)) * 8;
	if (y - cy != 0)
		ty = ((y - cy) / abs(y - cy)) * 8;
	if (game->collect_count == game->collectible_count)
	{
		show_sprite_image(&cx, &cy, image, game);
		mlx_put_image_to_window(game->m, game->w, game->empty, cx, cy);
		mlx_put_image_to_window(game->m, game->w, image[0].image, cx + tx, cy + ty);
		finish_game_after_free(game);
		return (1);
	}
	return (0);
}

void	show_sprite_image(int *cx, int *cy, t_image *image, t_data *game)
{
	int	tx;
	int	ty;
	int	i;

	tx = 0;
	ty = 0;
	if (game->target_x - *cx != 0)
		tx = ((game->target_x - *cx) / abs(game->target_x - *cx)) * 8;
	if (game->target_y - *cy != 0)
		ty = ((game->target_y - *cy) / abs(game->target_y - *cy)) * 8;
	mlx_put_image_to_window(game->m, game->w, game->empty, *cx, *cy);
	mlx_put_image_to_window(game->m, game->w, image[0].image, *cx + tx, *cy + ty);
	i = 1;
	while (i < 8)
	{
		mlx_put_image_to_window(game->m, game->w, game->empty, *cx, *cy);
		mlx_put_image_to_window(game->m, game->w, image[i].image, *cx + tx, *cy + ty);
		*cx += tx;
		*cy += ty;
		i++;
	}
}
