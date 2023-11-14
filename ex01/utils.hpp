#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>

# define TRUE	1
# define FALSE	0

std::string IntToString(int number);
int			StringToInteger(const std::string string, int *number);
int			IsValidInput(void);

#endif
