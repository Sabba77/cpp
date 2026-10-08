#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	Fixed d;

	c = b;

	std::cout << BOLD_CYAN << "Fixed a: " << a.getRawBits() << std::endl;
	std::cout << BOLD_CYAN << "Fixed b: " << b.getRawBits() << std::endl;
	std::cout << BOLD_CYAN << "Fixed c: " << c.getRawBits() << std::endl;
	
	d.setRawBits(15);
	std::cout << BOLD_CYAN << "Fixed d: " << d.getRawBits() << std::endl;


	return 0;
}