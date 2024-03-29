/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_component_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:33:24 by tayou             #+#    #+#             */
/*   Updated: 2023/04/26 14:55:57 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	set_image_when_moving_point_is_0_or_c(t_data *game);
int	set_image_when_moving_point_is_e(t_data *game);

int	move_by_component(t_data *game)
{
	char	component;
	int		move_sign;
	int		y;
	int		x;

	move_sign = 0;
	y = game->target_y / game->block_size;
	x = game->target_x / game->block_size;
	component = game->array_map[y][x];
	if (component == '0')
		move_sign = set_image_when_moving_point_is_0_or_c(game);
	else if (component == 'C')
	{
		move_sign = set_image_when_moving_point_is_0_or_c(game);
		game->array_map[y][x] = '0';
		game->collect_count++;
	}
	else if (component == 'E')
		move_sign = set_image_when_moving_point_is_e(game);
	return (move_sign);
}

int	set_image_when_moving_point_is_0_or_c(t_data *game)
{
	if (game->current_direction == 0)
		set_sprite_image_to_left(game);
	else if (game->current_direction == 1)
		set_sprite_image_to_right(game);
	else if (game->current_direction == 2)
		set_sprite_image_to_down(game);
	else if (game->current_direction == 3)
		set_sprite_image_to_up(game);
	return (1);
}

int	set_image_when_moving_point_is_e(t_data *game)
{
	if (game->collect_count == game->collectible_count)
	{
		
		if (game->current_direction == 0)
			set_sprite_image_to_left(game);
		else if (game->current_direction == 1)
			set_sprite_image_to_right(game);
		else if (game->current_direction == 2)
			set_sprite_image_to_down(game);
		else if (game->current_direction == 3)
			set_sprite_image_to_up(game);
		finish_game_after_free(game);
		return (1);
	}
	return (0);
}
