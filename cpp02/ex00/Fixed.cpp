#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << BOLD_CYAN << "DEFAULT CONSTRUCTOR CALLED!"<< RESET  << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << BOLD_CYAN << "COPY CONSTRUCTOR CALLED!" << RESET << std::endl;

	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << BOLD_CYAN << "COPY ASSIGNAMENT OPERATOR CALLED!"<< RESET  << std::endl;

	if (this == &other)
		return	*this;
	this->_rawBits = other.getRawBits();
	return	*this;
}

Fixed::~Fixed()
{
	std::cout << RED << "DESTRUCTOR CALLED!" << RESET << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << GREEN << "SET NUMBER " << raw << RESET << std::endl;
	this->_rawBits = raw;
}