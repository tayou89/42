/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:45 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:28:46 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_element_data(t_info *info, t_parsing *parsing)
{
	int	identifier;

	identifier = info->identifier;
	if (identifier == AMBIENT)
		get_ambient_data(&parsing->data, info, parsing);
	else if (identifier == CAMERA)
		get_camera_data(&parsing->data, info, parsing);
	else if (identifier == LIGHT)
		get_light_data(&parsing->data, info, parsing);
	else if (identifier == SPHERE)
		get_sphere_data(&parsing->data, info, parsing);
	else if (identifier == PLANE)
		get_plane_data(&parsing->data, info, parsing);
	else if (identifier == CYLINDER)
		get_cylinder_data(&parsing->data, info, parsing);
	free_info_data(info);
}
