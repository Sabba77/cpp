#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	try
	{
		PmergeMe	sorter(ac, av);

		sorter.printBefore();
		sorter.printAfter();
		sorter.printVectorTime();
		sorter.printListTime();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
