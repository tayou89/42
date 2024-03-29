/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_direction_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:33:36 by tayou             #+#    #+#             */
/*   Updated: 2023/04/26 13:31:39 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(t_data *game)
{
	int		move_sign;

	game->target_x = (game->player_x - 1) * game->block_size;
	game->target_y = game->current_y;
	game->current_direction = 0;
	move_sign = move_by_component(game);
	if (move_sign == 1)
	{
		game->player_x--;
		game->move_count++;
		ft_printf("Step: %d\n", game->move_count);
	}
}

void	move_right(t_data *game)
{
	int		move_sign;

	game->target_x = (game->player_x + 1) * game->block_size;
	game->target_y = game->current_y;
	game->current_direction = 1;
	move_sign = move_by_component(game);
	if (move_sign == 1)
	{
		game->player_x++;
		game->move_count++;
		ft_printf("Step: %d\n", game->move_count);
	}
}

void	move_down(t_data *game)
{
	int		move_sign;

	game->target_x = game->current_x;
	game->target_y = (game->player_y + 1) * game->block_size;
	game->current_direction = 2;
	move_sign = move_by_component(game);
	if (move_sign == 1)
	{
		game->player_y++;
		game->move_count++;
		ft_printf("Step: %d\n", game->move_count);
	}
}

void	move_up(t_data *game)
{
	int		move_sign;

	game->target_x = game->current_x;
	game->target_y = (game->player_y - 1) * game->block_size;
	game->current_direction = 3;
	move_sign = move_by_component(game);
	if (move_sign == 1)
	{
		game->player_y--;
		game->move_count++;
		ft_printf("Step: %d\n", game->move_count);
	}
}
