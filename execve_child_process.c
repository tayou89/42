#include "microshell.h"

void	connect_fd(int number, t_data *data);
void	execute_cd(char **path, t_data *data);

void	execve_child_process(int number, char **command, t_data *data)
{
	connect_fd(number, data);
	if (strcmp(command[0], "cd") == 0)
		execute_cd(&command[1], data);
	else
	{
		if (execve(command[0], command, data->envp) == -1)
			execute_error_process(EXECVE_ERROR, 1, command[0], data);
	}
}

void	connect_fd(int number, t_data *data)
{
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
