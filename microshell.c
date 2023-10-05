#include "microshell.h"

int	main(int argc, char **argv, char **envp)
{
	char	**parent_string;
	int		i;

	i = 1;
	while (argv[i] != (void *) 0)
	{
		argv += i;
		parent_string = get_parent_string(argv, &i);
		execute_parent_process(parent_string);
	}
}

char	**get_parent_string(char **argv, int *argv_index)
{
	int	i;

	i = 0;
	while (argv[i] != (void *) 0 && strcmp(argv[i], ";") != 0)
		i++;
	*argv_index += i;
	if (strcmp(argv[i], ";") == 0)
		(*argv_index)++;
	argv[i] = (void *) 0;
	return (argv);
}

void	execute_parent_process(char **parent_string)
{
	pid_t	*pid;
	int		child_count;
	int		i;

	child_count = get_pipe_count(parent_string);
	pid = malloc_pid(child_count);
	i = 0;
	while (i < 
	
}

int	get_child_count(char **parent_string)
{
	int	child_count;
	int	pipe_count;
	int	i;

	pipe_count = 0;
	i = 0;
	while (parent_string[i] != (void *) 0)
	{
		if (strcmp(parent_string[i], "|") == 0)
			pipe_count++;
		i++;
	}
	child_count = pipe_count + 1;
	return (child_count);
}

pid_t	*malloc_pid(int child_count)
{
	pid_t	*pid;

	pid = (pid_t *) malloc(sizeof(pid_t) * child_count);
	if (pid == (void *) 0)
		execute_error_process(SYS_ERROR, 1, (void *) 0);
	return (pid);
}
