#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

static void	exceptionTest(void)
{
	try
	{
		BitcoinExchange	test("data.csv");
		std::cout << BOLD_CYAN << "\n<INPUT FILE TEST>\n" << RESET << std::endl;

		std::cout << BOLD_CYAN << "non existant file --> could not open file" << RESET << std::endl;
		try
		{
			test.processFile("test/nonexistfile.txt");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "empty input file --> incorrect file header" << RESET << std::endl;
		try
		{
			test.processFile("test/empty.txt");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "bad header --> incorrect file header" << RESET << std::endl;
		try
		{
			test.processFile("test/badHeader.txt");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "non existant data.csv --> unable to open" << RESET << std::endl;
		try
		{
			BitcoinExchange	badData("none.csv");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "\n<CSV TEST>\n" << RESET << std::endl;
		std::cout << BOLD_CYAN << "csv bad header --> incorrect file header" << RESET << std::endl;
		try
		{
			BitcoinExchange	badData("test/badHeader.csv");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "csv with no comma --> bad line format" << RESET << std::endl;
		try
		{
			BitcoinExchange	badData("test/noComma.csv");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "csv with invalid date--> invalid date" << RESET << std::endl;
		try
		{
			BitcoinExchange	badData("test/invalidDate.csv");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "csv with negative rate--> invalid value" << RESET << std::endl;
		try
		{
			BitcoinExchange	badData("test/negativeRate.csv");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "csv with non digit rate--> invalid value" << RESET << std::endl;
		try
		{
			BitcoinExchange	badData("test/nonDigitRate.csv");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "csv with duplicate date--> duplicate date" << RESET << std::endl;
		try
		{
			BitcoinExchange	badData("test/duplicateDate.csv");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

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
	std::cout << BOLD_CYAN << "\n--- TEST 1: EXCEPTION ---" << RESET << std::endl;
	{
		exceptionTest();
	}
	std::cout << BOLD_CYAN << "\n--- TEST 2: EDGE CASES ---" << RESET << std::endl;
	{
		try
		{
			BitcoinExchange	edge("data.csv");
			edge.processFile("test/edge.txt");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

int	main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}

	std::cout << BOLD_CYAN << "=====< EXECUTE MY TEST >=====" << RESET << std::endl;
	try
	{
		executeTest(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}