#include "microshell.h"

void	connect_fd(t_data *data);

void	execve_child_process(char **command, t_data *data)
{
	connect_fd(data);
	if (execve(command[0], command, data->envp) == -1)
		execute_error_process(EXECVE_ERROR, 1, command[0], data);
}

void	connect_fd(t_data *data)
{
	if (data->child_number != 0)
		duplicate_fd_2(data->before_fd, 0, data);
	if (data->child_number != data->count.child - 1)
		duplicate_fd_2(data->fd[1], 1, data);
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->before_fd);
}
