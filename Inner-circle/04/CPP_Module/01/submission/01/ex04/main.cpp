#include "FileCopy.hpp"
#include "Error.hpp"

int	main(int argc, char *argv[])
{
	FileCopy	fileCopy;
	Error		error;
	std::string	fileName;
	std::string	copyFileName;

	if (argc != 4)
		error.HandleArgumentCountError();
	fileName = argv[1];
	copyFileName = fileName + COPYFILE_EXTENSION;
	fileCopy.SetWordChange(argv[2], argv[3]);
	fileCopy.SetFileInput(fileName);
	fileCopy.SetFileOutput(copyFileName);
	fileCopy.CopyFileWithWordChange();
	return (0);
}
