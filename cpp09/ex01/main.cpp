#include "RPN.hpp"
#include <iostream>

int	main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << YELLOW << "Usage: ./RPN \"expression (Reverse Polish Notation)\" " << RESET << std::endl;
		return 0;
	}
	try
	{
		RPN a(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}