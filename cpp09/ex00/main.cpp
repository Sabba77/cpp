#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

static void	executeTest(const std::string& filename)
{
	std::cout << BOLD_CYAN << "\n--- TEST 0: OCF ---" << RESET << std::endl;
	{
		BitcoinExchange a;
		std::cout << BOLD_CYAN << "db empty must print error:" << RESET << std::endl;
		a.processFile(filename);
		{
			BitcoinExchange	b("data.csv");
			BitcoinExchange	c(b);
			c = c;
			a = c;
		}
		std::cout << BOLD_CYAN << "\ndb full must print independently of b and c:" << RESET << std::endl;
		a.processFile(filename);
	}
}

int	main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}
	if (static_cast<std::string>(av[1]) == "--test")
	{
		std::cout << BOLD_CYAN << "=====< EXECUTE MY TEST >=====" << RESET << std::endl;
		if (ac != 3)
		{
			std::cerr << "Error: could not open file." << std::endl;
			return 0;
		}
		executeTest(av[2]);
		return 0;
	}
	std::cout << BOLD_CYAN << "=====< EXECUTE MAIN TEST >=====" << RESET << std::endl;
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