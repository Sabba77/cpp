#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << BOLD_CYAN << "Fixed a : " << a << std::endl;
	std::cout << "Fixed b : " << b << RESET << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}