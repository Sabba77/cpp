#include "iter.hpp"
#include <string>
#include <cctype>

static void	printHex(int n)
{
	std::cout << n << " in HEX is --> " << std::hex << n << std::dec << std::endl;

}

static void	incrementInt(int& n)
{
	n++;
}

static void printToUpper(std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
}

int	main(void)
{
	std::cout << "\n========== TEST INT ARRAY ==========\n" << std::endl;

	int	arrayInt[] = {1, 7, 15, 3, 77};
	iter(arrayInt, 5, printHex);

	std::cout << "\n========== TEST STRING ARRAY ==========\n" << std::endl;

	std::string	arrayStr[] = {"nine", "sine", "sone", "none"};
	iter(arrayStr, 4, printToUpper);
	for (int i = 0; i < 4; i++)
		std::cout << arrayStr[i] << std::endl;

}