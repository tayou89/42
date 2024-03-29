/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_component_image_address_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:32:02 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 23:22:28 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_image(void *mlx, int size, t_data *game);
void	get_enemy_image(void *mlx, int size, t_data *game);

void	get_component_image_address(t_data *game)
{
	void	*mlx;
	int		size;

	mlx = game->m;
	size = game->block_size;
	game->empty = mlx_xpm_file_to_image(mlx, "./xpm/empty.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(mlx, "./xpm/wall.xpm", &size, &size);
	game->coll = mlx_xpm_file_to_image(mlx, "./xpm/coll.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(mlx, "./xpm/exit.xpm", &size, &size);
	game->done = mlx_xpm_file_to_image(mlx, "./xpm/done.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(mlx, "./xpm/player.xpm", &size, &size);
	get_player_image(mlx, game->block_size, game);
	get_enemy_image(mlx, game->block_size, game);
}

void	get_player_image(void *mlx, int size, t_data *game)
{
	t_image	*p_left;
	t_image	*p_right;
	t_image	*p_down;
	t_image	*p_up;

	p_left = game->p_left;
	p_right = game->p_right;
	p_down = game->p_down;
	p_up = game->p_up;
	p_left[0].image = mlx_xpm_file_to_image(mlx, "./xpm/p_left1.xpm", &size, &size);
	p_left[1].image = mlx_xpm_file_to_image(mlx, "./xpm/p_left2.xpm", &size, &size);
	p_left[2].image = mlx_xpm_file_to_image(mlx, "./xpm/p_left3.xpm", &size, &size);
	p_left[3].image = mlx_xpm_file_to_image(mlx, "./xpm/p_left1.xpm", &size, &size);
	p_right[0].image = mlx_xpm_file_to_image(mlx, "./xpm/p_right1.xpm", &size, &size);
	p_right[1].image = mlx_xpm_file_to_image(mlx, "./xpm/p_right2.xpm", &size, &size);
	p_right[2].image = mlx_xpm_file_to_image(mlx, "./xpm/p_right3.xpm", &size, &size);
	p_right[3].image = mlx_xpm_file_to_image(mlx, "./xpm/p_right1.xpm", &size, &size);
	p_down[0].image = mlx_xpm_file_to_image(mlx, "./xpm/p_down1.xpm", &size, &size);
	p_down[1].image = mlx_xpm_file_to_image(mlx, "./xpm/p_down2.xpm", &size, &size);
	p_down[2].image = mlx_xpm_file_to_image(mlx, "./xpm/p_down3.xpm", &size, &size);
	p_down[3].image = mlx_xpm_file_to_image(mlx, "./xpm/p_down1.xpm", &size, &size);
	p_up[0].image = mlx_xpm_file_to_image(mlx, "./xpm/p_up1.xpm", &size, &size);
	p_up[1].image = mlx_xpm_file_to_image(mlx, "./xpm/p_up2.xpm", &size, &size);
	p_up[2].image = mlx_xpm_file_to_image(mlx, "./xpm/p_up3.xpm", &size, &size);
	p_up[3].image = mlx_xpm_file_to_image(mlx, "./xpm/p_up1.xpm", &size, &size);
}

void	get_enemy_image(void *mlx, int size, t_data *game)
{
	t_image	*e_left;
	t_image	*e_right;
	t_image	*e_down;
	t_image	*e_up;

	e_left = game->e_left;
	e_right = game->e_right;
	e_down = game->e_down;
	e_up = game->e_up;
	e_left[0].image = mlx_xpm_file_to_image(mlx, "./xpm/e_left1.xpm", &size, &size);
	e_left[1].image = mlx_xpm_file_to_image(mlx, "./xpm/e_left2.xpm", &size, &size);
	e_left[2].image = mlx_xpm_file_to_image(mlx, "./xpm/e_left3.xpm", &size, &size);
	e_left[3].image = mlx_xpm_file_to_image(mlx, "./xpm/e_left1.xpm", &size, &size);
	e_right[0].image = mlx_xpm_file_to_image(mlx, "./xpm/e_right1.xpm", &size, &size);
	e_right[1].image = mlx_xpm_file_to_image(mlx, "./xpm/e_right2.xpm", &size, &size);
	e_right[2].image = mlx_xpm_file_to_image(mlx, "./xpm/e_right3.xpm", &size, &size);
	e_right[3].image = mlx_xpm_file_to_image(mlx, "./xpm/e_right1.xpm", &size, &size);
	e_down[0].image = mlx_xpm_file_to_image(mlx, "./xpm/e_down1.xpm", &size, &size);
	e_down[1].image = mlx_xpm_file_to_image(mlx, "./xpm/e_down2.xpm", &size, &size);
	e_down[2].image = mlx_xpm_file_to_image(mlx, "./xpm/e_down3.xpm", &size, &size);
	e_down[3].image = mlx_xpm_file_to_image(mlx, "./xpm/e_down1.xpm", &size, &size);
	e_up[0].image = mlx_xpm_file_to_image(mlx, "./xpm/e_up1.xpm", &size, &size);
	e_up[1].image = mlx_xpm_file_to_image(mlx, "./xpm/e_up2.xpm", &size, &size);
	e_up[2].image = mlx_xpm_file_to_image(mlx, "./xpm/e_up3.xpm", &size, &size);
	e_up[3].image = mlx_xpm_file_to_image(mlx, "./xpm/e_up1.xpm", &size, &size);
}
