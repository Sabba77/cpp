#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>
#include <iostream>

template	<typename T> // can also use class instead of typename
void	swap(T& a, T& b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template	<typename T>
T	min(T a, T b)
{
	if (a <= b)
		return a;
	else
		return b;
}

template	<typename T>
T	max(T a, T b)
{
	if (a >= b)
		return a;
	else
		return b;
}


#endif