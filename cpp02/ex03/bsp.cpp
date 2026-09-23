#include "Point.hpp"

static Fixed cross(Point const p1, Point const p2, Point const p)
{
	Fixed	Cross;
	Cross = (p2.getX() - p1.getX()) * (p.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p.getX() - p1.getX());
	return Cross;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	z;
	Fixed	cross1(cross(a, b, point));
	Fixed	cross2(cross(b, c, point));
	Fixed	cross3(cross(c, a, point));

	if (cross1 > z && cross2 > z && cross3 > z)
		return true;
	else if (cross1 < z && cross2 < z && cross3 < z)
		return true;
	else if (cross1 == z || cross2 == z || cross3 == z)
		return false;
	else
		return false;
}