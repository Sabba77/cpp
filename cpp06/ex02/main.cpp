#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	srand(time(NULL));
	std::cout << BOLD_CYAN << "-- GENERATE 10 RANDOM BASE --" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base* p = generate();

		std::cout << "[" << i << "]  --> ";
		identify(p);
		std::cout << "[" << i << "]  --> ";
		identify(*p);

		delete p;
	}
	return 0;
}