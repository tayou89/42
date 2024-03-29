/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_has_valid_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:33:37 by tayou             #+#    #+#             */
/*   Updated: 2023/04/15 18:07:47 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_has_valid_path(char **map)
{
	char	**access_check_map;
	int		i;

	access_check_map = get_access_check_map(map);
	mark_accessible_area(acces_check_map, map);
	return (0);
}
