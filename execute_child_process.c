#include "microshell.h"

char	**get_child_string(char **parent_string, int *index);
void	execute_cd(char **path, t_data *data);
void	execute_command(char **child_string, t_data *data);

void	execute_child_process(char **parent_string, t_data *data)
{
	char	**child_string;
	int		i;

	initialize_child_data(parent_string, data);
	i = 0;
	data->child_number = 0;
	while (data->child_number < data->count.child)
	{
		child_string = get_child_string(&parent_string[i], &i);
		if (strcmp(child_string[0], "cd") == 0)
			execute_cd(child_string, data);
		else
			execute_command(child_string, data);
		data->child_number++;
	}
	close(data->before_fd);
}

char	**get_child_string(char **parent_string, int *index)
{
	int	i;

	i = 0;
	while (parent_string[i] != (void *) 0 && strcmp(parent_string[i], "|") != 0)
		i++;
	if (parent_string[i] == (void *) 0)
		*index += i;
	else
		*index = *index + i + 1;
	parent_string[i] = (void *) 0;
	return (parent_string);
}

void	execute_cd(char **path, t_data *data)
{
	int	path_count;

	path_count = 0;
	while (path[path_count] != (void *) 0)
		path_count++;
	if (path_count != 1)
		execute_error_process(CD_ARGV_ERROR, 1, (void *) 0, data);
	if (chdir(path[0]) == -1)
		execute_error_process(CD_PATH_ERROR, 1, path[0], data);
	free_data(data);
	exit(0);
}

void	execute_command(char **child_string, t_data *data)
{
	if (pipe(data->fd) == -1)
		execute_error_process(SYS_ERROR, 1, (void *) 0, data);
	data->pid[data->child_number] = fork();
	if (data->pid[data->child_number] == -1)
		execute_error_process(SYS_ERROR, 1, (void *) 0, data);
	if (data->pid[data->child_number] == 0)
		execve_child_process(child_string, data);
	close(data->before_fd);
	data->before_fd = duplicate_fd_1(data->fd[0], data);
	close(data->fd[0]);
	close(data->fd[1]);
}
