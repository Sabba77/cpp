#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << GREEN << a.getRawBits() << RESET << std::endl;
	std::cout << GREEN << b.getRawBits() << RESET << std::endl;
	std::cout << GREEN << c.getRawBits() << RESET << std::endl;

	return 0;
}