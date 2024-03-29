/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:54:36 by tayou             #+#    #+#             */
/*   Updated: 2023/05/10 20:18:08 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_extension(char *map_file_path);

void	check_map_extension(t_data *game)
{
	char	*right_extension;

	right_extension = ".ber";
	game->map.extension = get_extension(game->map.file_path);
	if (ft_strncmp(right_extension, game->map.extension, 4) != 0)
	{
		ft_printf("Error\n");
		ft_printf("Map file has wrong extension.\n");
		exit(0);
	}
}

char	*get_extension(char *map_file_path)
{
	int	extension_starting_point;
	int	i;

	i = 0;
	while (map_file_path[i] != '\0')
		i++;
	extension_starting_point = i - 4;
	return (&map_file_path[extension_starting_point]);
}
