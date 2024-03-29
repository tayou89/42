/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:51:11 by tayou             #+#    #+#             */
/*   Updated: 2023/04/22 22:12:44 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key_code, t_data *game);

void	control_player(t_data *game)
{
	mlx_key_hook(game->win_ptr, &key_press, game);
}

int	key_press(int key_code, t_data *game)
{
	char	**map;
	void	*mlx;
	void	*win;

	map = game->array_map;
	mlx = game->mlx_ptr;
	win = game->win_ptr;
	if (key_code == KEY_A)
		move_left(game);
	else if (key_code == KEY_D)
		move_right(game);
	else if (key_code == KEY_S)
		move_down(game);
	else if (key_code == KEY_W)
		move_up(game);
	return (0);
}
