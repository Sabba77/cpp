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

Fixed::Fixed(const int n)
{
	std::cout << BOLD_CYAN << "INT CONSTRUCTOR CALLED!" << RESET << std::endl;

	_rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << BOLD_CYAN << "FLOAT CONSTRUCTOR CALLED!" << RESET << std::endl;

	_rawBits = roundf( n * (1 << _fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << BOLD_CYAN << "COPY ASSIGNAMENT OPERATOR CALLED!"<< RESET  << std::endl;

	if (this == &other)
		return	*this;
	this->_rawBits = other._rawBits;
	return	*this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
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
float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}