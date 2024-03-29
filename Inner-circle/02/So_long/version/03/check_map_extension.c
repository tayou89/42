/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:29:07 by tayou             #+#    #+#             */
/*   Updated: 2023/04/14 23:42:29 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_extension(char *map_name);

void	check_map_extension(char *map_name)
{
	char	*map_extension;
	char	*right_extension;

	right_extension = ".ber";
	map_extension = get_extension(map_name);
	if (ft_strncmp(right_extension, map_extension, 4) != 0)
		exit(0);
}

char	*get_extension(char *map_name)
{
	int	extension_starting_point;
	int	i;

	i = 0;
	while (map_name[i] != '\0')
		i++;
	extension_starting_point = i - 4;
	return (&map_name[extension_starting_point]);
}
