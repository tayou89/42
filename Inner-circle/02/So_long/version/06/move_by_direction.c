/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:42:29 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 19:34:23 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *game)
{
	int		target_x;
	int		target_y;
	int		size;
	char	target_point;
	int		move_sign;

	size = game->block_size;
	target_x = (game->player_x - 1) * size;
	target_y = (game->player_y) * size;
	target_point = game->array_map[game->player_y][game->player_x - 1];
	move_sign = move_by_component(target_x, target_y, target_point, game);
	if (move_sign == 1)
	{
		game->player_x--;
		game->move_count++;
		ft_printf("Step: %d\n", game->move_count);
	}
}

void	move_right(t_data *game)
{
	int		target_x;
	int		target_y;
	int		size;
	char	target_point;
	int		move_sign;

	size = game->block_size;
	target_x = (game->player_x + 1) * size;
	target_y = (game->player_y) * size;
	target_point = game->array_map[game->player_y][game->player_x + 1];
	move_sign = move_by_component(target_x, target_y, target_point, game);
	if (move_sign == 1)
	{
		game->player_x++;
		game->move_count++;
		ft_printf("Step: %d\n", game->move_count);
	}
}

void	move_down(t_data *game)
{
	int		target_x;
	int		target_y;
	int		size;
	char	target_point;
	int		move_sign;

	size = game->block_size;
	target_x = (game->player_x) * size;
	target_y = (game->player_y + 1) * size;
	target_point = game->array_map[game->player_y + 1][game->player_x];
	move_sign = move_by_component(target_x, target_y, target_point, game);
	if (move_sign == 1)
	{
		game->player_y++;
		game->move_count++;
		ft_printf("Step: %d\n", game->move_count);
	}
}

void	move_up(t_data *game)
{
	int		target_x;
	int		target_y;
	int		size;
	char	target_point;
	int		move_sign;

	size = game->block_size;
	target_x = (game->player_x) * size;
	target_y = (game->player_y - 1) * size;
	target_point = game->array_map[game->player_y - 1][game->player_x];
	move_sign = move_by_component(target_x, target_y, target_point, game);
	if (move_sign == 1)
	{
		game->player_y--;
		game->move_count++;
		ft_printf("Step: %d\n", game->move_count);
	}
}
