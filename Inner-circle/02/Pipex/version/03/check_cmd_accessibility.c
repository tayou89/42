/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_accessibility.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:37:04 by tayou             #+#    #+#             */
/*   Updated: 2023/05/24 23:09:24 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd_split_array(char *cmd, t_data *data);
void	find_cmd_accessible_path(char *cmd, t_data *data);

void	check_cmd_accessibility(char *cmd, t_data *data)
{
	get_cmd_split_array(cmd, data);
	if (access(data->cmd.split_array[0], F_OK) == 0
		&& access(data->cmd.split_array[0], X_OK) == 0)
	{
		data->cmd.path = data->cmd.split_array[0];
		data->flag.find_accessible_path = SUCCESS;
		return ;
	}
	find_cmd_accessible_path(data->cmd.split_array[0], data);
}

void	get_cmd_split_array(char *cmd, t_data *data)
{
	while (data->cmd.split_array == (void *) 0)
		data->cmd.split_array = ft_split(cmd, ' ');
}

void	find_cmd_accessible_path(char *cmd, t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd.directory[i] != (void *) 0)
	{
		data->cmd.path = ft_strjoin(data->cmd.directory[i], cmd);
		if (data->cmd.path == (void *) 0)
			continue ;
		if (access(data->cmd.path, F_OK) == 0
			&& access(data->cmd.path, X_OK) == 0)
		{
			data->flag.find_accessible_path = SUCCESS;
			break ;
		}
		free(data->cmd.path);
		data->cmd.path = (void *) 0;
		i++;
	}
	if (data->cmd.directory[i] == (void *) 0)
		print_error_message(CMD_ERROR);
}
