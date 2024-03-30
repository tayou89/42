#include <cctype>
#include <iostream>
#include <cstdlib>

void	check_exception(int argc);
void	make_string_toupper(char *string);

int	main(int argc, char **argv)
{
	check_exception(argc);
	for (int i = 1; argv[i] != (void *) 0; i++)
	{
		make_string_toupper(argv[i]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return (0);
}

void	check_exception(int argc)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		exit(0);
	}
}

void	make_string_toupper(char *string)
{
	for (int i = 0; string[i] != '\0'; i++)
		string[i] = toupper(string[i]);
}
