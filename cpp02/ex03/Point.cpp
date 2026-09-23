#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(0) , y(0)
{/* 
	std::cout << GREEN << "POINT DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl; */
}

Point::~Point()
{/* 
	std::cout << GREEN << "POINT DESTRUCTOR CALLED!"<< RESET  << std::endl; */
}

Point::Point(float const a, float const b) : x(Fixed(a)) , y(Fixed(b))
{/* 
	std::cout << GREEN << "POINT CONSTRUCTOR x AND y CALLED!"<< RESET  << std::endl; */
}

Point::Point(const Point& other) : x(other.getX()), y(other.getY())
{/* 
	std::cout << GREEN << "POINT COPY CONSTRUCTOR CALLED!" << RESET << std::endl; */
}

Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return *this;
	const_cast<Fixed&>(this->x) = other.getX();
	const_cast<Fixed&>(this->y) = other.getY();
	return *this;
}

Fixed const& Point::getX(void) const
{
	return (this->x);
}

Fixed const& Point::getY(void) const
{
	return (this->y);
}