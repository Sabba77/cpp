#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point	a(2, 7);
	Point	b(-3, 5);
	Point	c(11, -15);
	Point	pIn(2.2, 2.3);
	Point	pOut(-3, -9.2);
	Point	pEdge((a.getX().toFloat() + b.getX().toFloat()) / 2, (a.getY().toFloat() + b.getY().toFloat()) / 2);
	Point	d(7, 3);
	Point	e(13, 3);
	Point	f(10, 10);
	Point	pOut2(9, 4);

	std::cout << "point in : "  << bsp(a, b, c, pIn) << std::endl;
	std::cout << "point out : " << bsp(a, b, c, pOut) << std::endl;
	std::cout << "point p = a : " << bsp(a, b, c, a) << std::endl;
	std::cout << "point pEdge : " << bsp(a, b, c, pEdge) << std::endl;

	std::cout << "point pOut2 : " << bsp(d, e, f, pOut2) << std::endl;
	return 0;
}