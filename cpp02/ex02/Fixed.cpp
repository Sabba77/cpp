#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << RED << "DEFAULT CONSTRUCTOR CALLED!"<< RESET  << std::endl;
}

Fixed::~Fixed()
{
	std::cout << RED << "DESTRUCTOR CALLED!" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << RED << "COPY CONSTRUCTOR CALLED!" << RESET << std::endl;

	*this = other;
}

Fixed::Fixed(const int n)
{
	std::cout << RED << "INT CONSTRUCTOR CALLED!" << RESET << std::endl;

	_rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << RED << "FLOAT CONSTRUCTOR CALLED!" << RESET << std::endl;

	_rawBits = roundf( n * (1 << _fractionalBits));
}



Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << RED << "COPY ASSIGNAMENT OPERATOR CALLED!" << RESET  << std::endl;

	if (this == &other)
		return	*this;
	this->_rawBits = other._rawBits;
	return	*this;
}


Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed const&	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

Fixed const&	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}



Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	res;

	res.setRawBits(this->_rawBits + other._rawBits);
	return res;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	res;

	res.setRawBits(this->_rawBits - other._rawBits);
	return (res);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	res;
	
	res.setRawBits((this->_rawBits * other._rawBits) >> _fractionalBits);
	return res;
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	res;

	res.setRawBits((this->_rawBits << _fractionalBits) / other._rawBits);
	return res;
}


Fixed	&Fixed::operator++()
{
	++(this->_rawBits);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);

	this->_rawBits++;
	return copy;
}

Fixed	&Fixed::operator--()
{
	--(this->_rawBits);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);

	this->_rawBits--;
	return copy;
}


bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_rawBits < other._rawBits);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_rawBits > other._rawBits);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawBits != other._rawBits);
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

int	Fixed::getRawBits(void) const
{
	std::cout << GREEN << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits(int const raw)
{
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
