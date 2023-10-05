#include "microshell.h"

int	ft_strlen(char *string)
{
	int	size;
	int	i;

	if (string == (void *) 0)
		return (0);
	i = 0;
	while (string[i] != '\0')
		i++;
	size = i;
	return (size);
}
