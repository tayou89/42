#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

# define SYS_ERROR	0

typedef struct s_count
{
	int	process;
}	t_count;

typedef struct s_process
{
	char				**string;
	t_count				count;
	struct s_process	*child;
}	t_process;

typedef struct s_data
{
	t_process	*parent;
	t_count		count;
}	t_data;

#endif
