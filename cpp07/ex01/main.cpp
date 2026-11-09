#include "iter.hpp"

#include <string>
#include <cctype>
#include <iostream>

#define RED			"\033[31m"
#define STRIKE_RED	"\033[9;31m"
#define GREEN		"\033[32m"
#define YELLOW		"\x1b[33m"
#define BOLD_CYAN	"\033[1;36m"
#define BLACK_GRAY	"\033[90m"
#define BLK_MAGENTA	"\x1b[95m"

#define RESET		"\033[0m"

//==================================================================================================================//

template	<typename P>
void	printType(const P& p)
{
	std::cout << BLK_MAGENTA << p << RESET << std::endl;
}

class	LittleNum
{
private:
	int		num;

public:
	LittleNum() : num(0)
	{
	}

	int		getNum() const
	{
		return this->num;
	}
	void	setNum(int n)
	{
		this->num = n;
	}
};

//==================================================================================================================//

static void	printHex(int n)
{
	std::cout << BLK_MAGENTA << n << " in HEX is --> " << std::hex << n << std::dec << RESET << std::endl;
}

static void	incrementDouble(double& n)
{
	n++;
}

static void	incrementInt(int& n)
{
	n++;
}

static void	incrementClassInt(LittleNum& ln)
{
	ln.setNum(ln.getNum() + 1);
}

static void	printClassInt(const LittleNum& ln)
{
	std::cout << BLK_MAGENTA << ln.getNum() << RESET << std::endl;
}

static void printToUpper(std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = toupper(static_cast<unsigned char>(str[i]));
}

static void	toUpper(char& n)
{
	n = toupper(static_cast<unsigned char>(n));
}

static int*	createArrayInt(void)
{
	static int arrInt[] = { 1, 2, 3, 4 };
	return (arrInt);
}

//==================================================================================================================//

int	main(void)
{
	std::cout << BOLD_CYAN << "\n========== TEST INT ARRAY ==========\n" << RESET << std::endl;

	std::cout << BOLD_CYAN << "TEST 1: non-const int array modify, must be incresed by 1\n" << RESET << std::endl;

	int	arrayInt[] = {1, 7, 15, 3, 77};
	iter(arrayInt, 5, printHex);
	std::cout << std::endl;
	iter(arrayInt, 5, incrementInt);
	for (int i = 0; i < 5; i++)
		printHex(arrayInt[i]);

	std::cout << BOLD_CYAN << "\nTEST 2: const int array can be used, but not modified\n" << RESET << std::endl;

	const int	constArrayInt[] = { 23, 3, 7, 18, 6 };
	iter(constArrayInt, 5, printHex);
	// iter(constArrayInt, 5, incrementInt); // compile error


	std::cout << BOLD_CYAN << "\n========== TEST STRING ARRAY ==========\n" << RESET << std::endl;
	
	std::cout << BOLD_CYAN << "TEST 1 : print to upper\n" << RESET << std::endl;
	
	std::string	arrayStr[] = { "nine", "sine", "sone", "none" };
	for (int i = 0; i < 4; i++)
		std::cout << BLK_MAGENTA << arrayStr[i] << RESET << std::endl;
	std::cout << std::endl;
	iter(arrayStr, 4, printToUpper);
	for (int i = 0; i < 4; i++)
		std::cout << BLK_MAGENTA << arrayStr[i] << RESET << std::endl;

	std::cout << BOLD_CYAN << "TEST 2 : parzial size" << RESET << std::endl;
	std::cout << BOLD_CYAN << "size = 0 \n" << RESET << std::endl;
	iter(arrayStr, 0, printType<std::string>);
	std::cout << BOLD_CYAN << "size = 2 \n" << RESET << std::endl;
	iter(arrayStr, 2, printType<std::string>);


	std::cout << BOLD_CYAN << "\n========== TEST DOUBLE ARRAY ==========\n" << RESET << std::endl;

	double	arrayDouble[] = {2.3, 1.6, 0.5, 0.87, 5.63};
	for (int i = 0; i < 5; i++)
		std::cout << BLK_MAGENTA << arrayDouble[i] << RESET << std::endl;
	std::cout << std::endl;
	iter(arrayDouble, 5, incrementDouble);
	for (int i = 0; i < 5; i++)
		std::cout << BLK_MAGENTA << arrayDouble[i] << RESET << std::endl;


	std::cout << BOLD_CYAN << "\n========== TEST CHAR ARRAY ==========\n" << RESET << std::endl;

	char	arrayChar[] = {'h', 'e', 'l', 'l', 'o'};
	for (int i = 0; i < 5; i++)
		std::cout << BLK_MAGENTA << arrayChar[i] << RESET;
	std::cout << std::endl;
	iter(arrayChar, 5, toUpper);
	for (int i = 0; i < 5; i++)
		std::cout << BLK_MAGENTA << arrayChar[i] << RESET;
	std::cout << std::endl;

	std::cout << BOLD_CYAN << "\n========== TEST CLASS ARRAY ==========\n" << RESET << std::endl;
	
	std::cout << BOLD_CYAN << "TEST 1: setNum() \n" << RESET << std::endl;
	LittleNum	arrayClass[5];
	iter(arrayClass, 5, incrementClassInt);
	iter(arrayClass, 5, incrementClassInt);
	iter(arrayClass, 5, incrementClassInt);
	for (int i = 0; i < 5; i++)
		std::cout << BLK_MAGENTA << arrayClass[i].getNum() << RESET;
	std::cout << std::endl;

	std::cout << BOLD_CYAN << "TEST 2: const class can be used, but not modified \n" << RESET << std::endl;

	const LittleNum constClass[5];
	/* for (int i = 0; i < 5; i++)
		iter(constClass, 5, incrementClassInt); */ // compile error
	iter(constClass, 5, printClassInt);

	std::cout << BOLD_CYAN << "\n========== TEST TEMPLATE FUNCTION ==========\n" << RESET << std::endl;

	const int	arrayInt2[] = { 1, 0, 2, 4 };
	iter(arrayInt2, 4, printType<int>);
	std::cout << std::endl;
	std::string	arrayStr2[] = { "nop", "yep", "nine0", "ten10" };
	iter(arrayStr2, 4, printType<std::string>);

	std::cout << BOLD_CYAN << "\n========== TEST int* ==========\n" << RESET << std::endl;
	iter(createArrayInt(), 4, printHex);
}