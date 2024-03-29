/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:29:07 by tayou             #+#    #+#             */
/*   Updated: 2023/04/20 21:18:27 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_extension(char *map_file_path);

void	check_map_extension(t_data *game)
{
	char	*map_extension;
	char	*right_extension;

	right_extension = ".ber";
	map_extension = get_extension(game->map_file_path);
	if (ft_strncmp(right_extension, map_extension, 4) != 0)
		exit(0);
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
