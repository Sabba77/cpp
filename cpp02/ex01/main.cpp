#include "Fixed.hpp"

int main( void )
{

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << GREEN << "a is " << a << RESET << std::endl;
	std::cout << GREEN << "b is " << b << RESET <<std::endl;
	std::cout << GREEN << "c is " << c << RESET <<std::endl;
	std::cout << GREEN << "d is " << d << RESET <<std::endl;

	std::cout << GREEN << "a is " << a.toInt() << " as integer" << RESET << std::endl;
	std::cout << GREEN << "b is " << b.toInt() << " as integer" << RESET << std::endl;
	std::cout << GREEN << "c is " << c.toInt() << " as integer" << RESET << std::endl;
	std::cout << GREEN << "d is " << d.toInt() << " as integer" << RESET << std::endl;
	return 0;
}