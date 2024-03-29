/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game_after_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:31:24 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 15:40:51 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	finish_game_after_free(t_data *game)
{
	free_mallocated_data(game);
	ft_printf("Thank You For Playing!\n");
	exit(0);
	return (0);
}
