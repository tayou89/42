/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game_after_free_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:31:02 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 22:31:13 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	finish_game_after_free(t_data *game)
{
	free_mallocated_data(game);
	ft_printf("Thank You For Playing!\n");
	exit(0);
	return (0);
}
