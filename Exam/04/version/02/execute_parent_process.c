#include "microshell.h"

char	**get_parent_string(char **argv, int *argv_index);
void	wait_child_process(t_data *data);

void	execute_parent_process(char **argv, t_data *data)
{
	char	**parent_string;
	int		i;

	i = 1;
	while (argv[i] != (void *) 0)
	{
		parent_string = get_parent_string(&argv[i], &i);
		execute_child_process(parent_string, data);
		wait_child_process(data);
	}
}

char	**get_parent_string(char **argv, int *argv_index)
{
	int	i;

	i = 0;
	while (argv[i] != (void *) 0 && strcmp(argv[i], ";") != 0)
		i++;
	if (argv[i] == (void *) 0)
		*argv_index += i;
	else
		*argv_index = *argv_index + i + 1;
	argv[i] = (void *) 0;
	return (argv);
}

void	wait_child_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count.child)
	{
		if (waitpid(data->pid[i], &data->status, 0) == -1)
			execute_error_process(SYS_ERROR, 1, (void *) 0, data);
		i++;
	}
	free(data->pid);
}
