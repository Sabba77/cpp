#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}

	try
	{
		BitcoinExchange		b("data.csv");
		b.processFile(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}