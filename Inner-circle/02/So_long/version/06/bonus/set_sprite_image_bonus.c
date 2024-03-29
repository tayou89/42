/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:16:01 by tayou             #+#    #+#             */
/*   Updated: 2023/04/26 15:31:25 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_new_image(int new_x, int new_y, int image_number, t_data *game);

void	set_sprite_image_to_left(t_data *game)
{
	int	new_point_x;
	int	new_point_y;
	int	image_number;
	int	i;
	double start;

	i = 1;
	image_number = 0;
	while (i <= game->block_size)
	{
		start = (double) clock();
		while (difftime((double) clock(), start) < 1000)
		new_point_x = game->current_x - i;
		new_point_y = game->current_y;
		put_new_image(new_point_x, new_point_y, image_number, game);
		if (i % (game->block_size / 4) == 0)
			image_number++;
		i++;
	}
}

void	set_sprite_image_to_right(t_data *game)
{
	int	new_point_x;
	int	new_point_y;
	int	image_number;
	int	i;

	i = 1;
	image_number = 0;
	while (i <= game->block_size)
	{
		new_point_x = game->current_x + i;
		new_point_y = game->current_y;
		put_new_image(new_point_x, new_point_y, image_number, game);
		if (i % 16 == 0)
			image_number++;
		i++;
	}
}

void	set_sprite_image_to_down(t_data *game)
{
	int	new_point_x;
	int	new_point_y;
	int	image_number;
	int	i;

	i = 1;
	image_number = 0;
	while (i <= game->block_size)
	{
		new_point_x = game->current_x;
		new_point_y = game->current_y + i;
		put_new_image(new_point_x, new_point_y, image_number, game);
		if (i % 16 == 0)
			image_number++;
		i++;
	}
}

void	set_sprite_image_to_up(t_data *game)
{
	int	new_point_x;
	int	new_point_y;
	int	image_number;
	int	i;

	i = 1;
	image_number = 0;
	while (i <= game->block_size)
	{
		new_point_x = game->current_x;
		new_point_y = game->current_y - i;
		put_new_image(new_point_x, new_point_y, image_number, game);
		if (i % 16 == 0)
			image_number++;
		i++;
	}
}

void	put_new_image(int new_x, int new_y, int image_number, t_data *game)
{
	int dir;
	double	start;
	double	diff;

	dir = game->current_direction;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->empty, game->current_x, game->current_y);
		start = (double) clock();
		diff = difftime((double) clock(), start);
		while (diff < 500)
			diff = difftime((double) clock(), start);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->empty, game->target_x, game->target_y);
		start = (double) clock();
		diff = difftime((double) clock(), start);
		while (diff < 500)
			diff = difftime((double) clock(), start);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->player[dir][image_number].image, \
				new_x, new_y);
}
