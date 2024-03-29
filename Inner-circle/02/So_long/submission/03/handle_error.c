/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:42:22 by tayou             #+#    #+#             */
/*   Updated: 2023/05/14 18:46:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	execute_process_for_open_error(t_data *game)
{
	free_2d_string_array(game->map.array);
	ft_printf("Error.\nOpening file is failed.\n");
	exit(2);
}

void	execute_process_for_read_error(void)
{
	ft_printf("Error.\nReading file is failed.\n");
	exit(2);
}

void	execute_process_for_malloc_array_error(t_data *game)
{
	free_2d_string_array(game->map.array);
	if (game->map.line != (void *) 0)
	{
		free(game->map.line);
		game->map.line = (void *) 0;
	}
	ft_printf("Error.\nMemory allocating for array is failed.\n");
	exit(2);
}
