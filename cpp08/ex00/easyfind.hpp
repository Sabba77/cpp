#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>

template	<typename T>
typename T::iterator easyfind(T* container, int n)
{
	typename T::iterator it = std::find(container->begin(), container->end(), n);
	if (it == container->end())
		throw std::runtime_error("Value not found");
	return it;
}

#endif