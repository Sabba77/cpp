#include "Span.hpp"

Span::Span()
{
}

Span::Span(const Span& other) : N(other.N), arr(other.arr), _sorted(other._sorted)
{
	std::cout << BLACK_GRAY << "COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}

Span::Span(unsigned int n) : N(n), _sorted(false)
{
	std::cout << BLACK_GRAY << "PARAMETRIC CONSTRUCTOR CALLED" << RESET << std::endl;
	
	arr.reserve(N);
}

Span&	Span::operator=(const Span& other)
{
	std::cout << BLACK_GRAY << "COPY ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;

	if (this != &other)
	{
		N = other.N;
		_sorted = other._sorted;
		arr = other.arr;
	}
	return *this;
}

Span::~Span()
{
	std::cout << BLACK_GRAY << "DESTRUCTOR CALLED" << RESET << std::endl;
}

void	Span::sortArr()
{
	std::sort(arr.begin(), arr.end());
	_sorted = true;
}

void	Span::addNumber(int n)
{
	if (arr.size() < N)
		arr.push_back(n);
	else
		throw std::range_error("Impossible to add, no space available!");
	_sorted = false;
}

int		Span::shortestSpan()
{
	if (arr.size() < 2)
		throw	std::range_error("No span can be found!");
	int		distance = 0;
	std::vector<int>::iterator	it = arr.begin();
	if (!_sorted)
	sortArr();
	int		span = *(it + 1) - *it;
	for (unsigned int i = 0; i <= N; i++)
	{
		if (it == arr.end() - 1)
			break;
		distance = *(it + 1) - *it;
		if (distance < span)
			span = distance;
		++it;
	}
	return span;
}

int		Span::longestSpan()
{
	if (arr.size() < 2)
		throw	std::range_error("No span can be found!");
	if (!_sorted)
		sortArr();
	std::vector<int>::iterator it1 = arr.begin(), it2 = arr.end() - 1;
	return *it2 - *it1;
}
