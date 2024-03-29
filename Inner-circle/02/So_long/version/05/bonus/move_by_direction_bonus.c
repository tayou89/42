/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_direction_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:33:36 by tayou             #+#    #+#             */
/*   Updated: 2023/04/24 10:51:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(t_data *game)
{
	int		target_x;
	int		target_y;
	int		size;
	int		move_sign;

	size = game->block_size;
	target_x = (game->player_x - 1) * size;
	target_y = (game->player_y) * size;
	game->target_x = target_x;
	game->target_y = target_y;
	move_sign = move_by_component(target_x, target_y, game->p_left, game);
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
	int		move_sign;

	size = game->block_size;
	target_x = (game->player_x + 1) * size;
	target_y = (game->player_y) * size;
	game->target_x = target_x;
	game->target_y = target_y;
	move_sign = move_by_component(target_x, target_y, game->p_right, game);
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
	int		move_sign;

	size = game->block_size;
	target_x = (game->player_x) * size;
	target_y = (game->player_y + 1) * size;
	game->target_x = target_x;
	game->target_y = target_y;
	move_sign = move_by_component(target_x, target_y, game->p_down, game);
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
	int		move_sign;

	size = game->block_size;
	target_x = (game->player_x) * size;
	target_y = (game->player_y - 1) * size;
	game->target_x = target_x;
	game->target_y = target_y;
	move_sign = move_by_component(target_x, target_y, game->p_up, game);
	if (move_sign == 1)
	{
		game->player_y--;
		game->move_count++;
		ft_printf("Step: %d\n", game->move_count);
	}
}
