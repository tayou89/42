#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	uintptr_t	unsignedIntPTR = Serializer::serialize(&data);
	Data		*dataPTR = Serializer::deserialize(unsignedIntPTR);

	std::cout << "Data address: " << &data << '\n';
	std::cout << "unsignedIntPTR(decimal): " << unsignedIntPTR << '\n';
	std::cout << std::hex << "unsignedIntPTR(hexadecimal): 0x" << unsignedIntPTR << '\n';
	std::cout << "dataPTR: " << dataPTR << '\n';

	return (0);
}