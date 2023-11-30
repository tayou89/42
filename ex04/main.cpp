#include "FileReplace.hpp"
#include "Error.hpp"

int	main(int argc, char *argv[])
{
	FileReplace	fileReplace;
	std::string	replaceExtension = ".replace";
	Error		error;

	if (argc != 4)
		error.HandleArgumentCountError();
	fileReplace.SetReplacingWord(argv[2], argv[3]);
	fileReplace.OpenInputFile(argv[1]);
	fileReplace.OpenOutputFile(argv[1] + replaceExtension);
	fileReplace.MakeReplacedFile();
	return (0);
}
