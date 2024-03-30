#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc == 2)
		harl.setComplainLevel(argv[1]);
	harl.printFilteredComplain();
	return (0);
}
