#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : _x(0) , _y(0)
{
	std::cout << GREEN << "POINT DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl;
}

Point::~Point()
{
	std::cout << GREEN << "POINT DESTRUCTOR CALLED!"<< RESET  << std::endl;
}

Point::Point(float const a, float const b) : _x(Fixed(a)) , _y(Fixed(b))
{
	std::cout << GREEN << "POINT CONSTRUCTOR _x AND _y CALLED!"<< RESET  << std::endl;
}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY())
{
	std::cout << GREEN << "POINT COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
}