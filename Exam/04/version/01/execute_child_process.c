#include "microshell.h"

char	**get_child_string(char **parent_string, int *index);

void	execute_child_process(char **parent_string, t_data *data)
{
	int		child_number;
	char	**child_string;
	int		i;

	initialize_child_data(parent_string, data);
	child_number = 0;
	i = 0;
	while (child_number < data->count.child)
	{
		child_string = get_child_string(parent_string, &i);
		data->pid[child_number] = fork();
		if (data->pid[child_number] == -1)
			execute_error_process(SYS_ERROR, 1, (void *) 0, data);
		if (data->pid[child_number] == 0)
			execve_child_process(child_number, child_string, data);
		child_number++;
	}
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
