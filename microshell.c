#include "microshell.h"

void	check_argc(int argc);

int	main(int argc, char **argv, char **envp)
{
	t_data data;

	check_argc(argc);
	data.envp = envp;
	execute_parent_process(argv, &data);
	return (data.status);
}

void	check_argc(int argc)
{
	if (argc <= 1)
		exit(0);
}
