#include "FileReplace.hpp"

int	main(int argc, const char *argv[])
{
	FileReplace	fileReplace(argc - 1, &argv[1]);

	fileReplace.MakeReplacedFile();
	return (0);
}
