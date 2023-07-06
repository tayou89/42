/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:45:13 by tayou             #+#    #+#             */
/*   Updated: 2023/07/06 13:09:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data all;

	if (check_exception_exist(argc, argv, &all) == TRUE)
		return (0);
	if (make_fork_array(&all) == FALSE)
		return (1);
	if (make_philo_list(&all) == FALSE)
		return (1);
	if (pthread_mutex_init(&all.mutex, (void *) 0) != 0)
		return (1);
	print_data(&all);
	system("leaks philo");
	return (0);
}
