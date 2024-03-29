/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_component_image_address_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:32:02 by tayou             #+#    #+#             */
/*   Updated: 2023/04/27 15:33:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_image(t_data *game);
void	get_enemy_image(t_data *game);
void	*get_xpm_image(char *file_path, t_data *game);

void	get_component_image_address(t_data *game)
{
	void	*mlx;
	int		size;

	mlx = game->mlx_ptr;
	size = game->block_size;
	game->empty = mlx_xpm_file_to_image(mlx, "./xpm/empty.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(mlx, "./xpm/wall.xpm", &size, &size);
	game->coll = mlx_xpm_file_to_image(mlx, "./xpm/coll.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(mlx, "./xpm/exit.xpm", &size, &size);
	game->done = mlx_xpm_file_to_image(mlx, "./xpm/done.xpm", &size, &size);
	get_player_image(game);
	get_enemy_image(game);
}

void	get_player_image(t_data *game)
{
	game->player[0][0].image = get_xpm_image("./xpm/p_left1.xpm", game);
	game->player[0][1].image = get_xpm_image("./xpm/p_left2.xpm", game);
	game->player[0][2].image = get_xpm_image("./xpm/p_left1.xpm", game);
	game->player[0][3].image = get_xpm_image("./xpm/p_left3.xpm", game);
	game->player[1][0].image = get_xpm_image("./xpm/p_right1.xpm", game);
	game->player[1][1].image = get_xpm_image("./xpm/p_right2.xpm", game);
	game->player[1][2].image = get_xpm_image("./xpm/p_right1.xpm", game);
	game->player[1][3].image = get_xpm_image("./xpm/p_right3.xpm", game);
	game->player[2][0].image = get_xpm_image("./xpm/p_down1.xpm", game);
	game->player[2][1].image = get_xpm_image("./xpm/p_down2.xpm", game);
	game->player[2][2].image = get_xpm_image("./xpm/p_down1.xpm", game);
	game->player[2][3].image = get_xpm_image("./xpm/p_down3.xpm", game);
	game->player[3][0].image = get_xpm_image("./xpm/p_up1.xpm", game);
	game->player[3][1].image = get_xpm_image("./xpm/p_up2.xpm", game);
	game->player[3][2].image = get_xpm_image("./xpm/p_up1.xpm", game);
	game->player[3][3].image = get_xpm_image("./xpm/p_up3.xpm", game);
}

void	get_enemy_image(t_data *game)
{
	game->enemy[0][0].image = get_xpm_image("./xpm/e_left1.xpm", game);
	game->enemy[0][1].image = get_xpm_image("./xpm/e_left2.xpm", game);
	game->enemy[0][2].image = get_xpm_image("./xpm/e_left1.xpm", game);
	game->enemy[0][3].image = get_xpm_image("./xpm/e_left3.xpm", game);
	game->enemy[1][0].image = get_xpm_image("./xpm/e_right1.xpm", game);
	game->enemy[1][1].image = get_xpm_image("./xpm/e_right2.xpm", game);
	game->enemy[1][2].image = get_xpm_image("./xpm/e_right1.xpm", game);
	game->enemy[1][3].image = get_xpm_image("./xpm/e_right3.xpm", game);
	game->enemy[2][0].image = get_xpm_image("./xpm/e_down1.xpm", game);
	game->enemy[2][1].image = get_xpm_image("./xpm/e_down2.xpm", game);
	game->enemy[2][2].image = get_xpm_image("./xpm/e_down1.xpm", game);
	game->enemy[2][3].image = get_xpm_image("./xpm/e_down3.xpm", game);
	game->enemy[3][0].image = get_xpm_image("./xpm/e_up1.xpm", game);
	game->enemy[3][1].image = get_xpm_image("./xpm/e_up2.xpm", game);
	game->enemy[3][2].image = get_xpm_image("./xpm/e_up1.xpm", game);
	game->enemy[3][3].image = get_xpm_image("./xpm/e_up3.xpm", game);
}

void	*get_xpm_image(char *file_path, t_data *game)
{
	void	*image;

	image = mlx_xpm_file_to_image(game->mlx_ptr, \
			file_path, &game->block_size, &game->block_size);
	return (image);
}
