#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"


class	Point
{
private:
	Fixed const	x;
	Fixed const	y;

public:
	Point();

	Point(float const a, float const b);
	Point(const Point& other);

	Point& operator=(const Point& other);

	Fixed const&	getX(void) const;
	Fixed const&	getY(void) const;

	~Point();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif