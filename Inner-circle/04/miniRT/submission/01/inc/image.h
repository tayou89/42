/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:36:27 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:36:27 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "initialize.h"
# include "hit.h"

void	draw_image_by_ray_tracing(t_mlx *mlx, t_data *data);
int		phong_lighting(t_rec *rec, t_data *data, t_ray ray);
int		color_get_trgb(int t, int r, int g, int b);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
#endif