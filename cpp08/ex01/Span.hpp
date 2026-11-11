#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#define RED			"\033[31m"
#define STRIKE_RED	"\033[9;31m"
#define GREEN		"\033[32m"
#define YELLOW		"\x1b[33m"
#define BOLD_CYAN	"\033[1;36m"
#define BLACK_GRAY	"\033[90m"
#define RESET		"\033[0m"

class Span
{
private:
	unsigned int		N;
	std::vector<int>	arr;
	bool				_sorted;
	Span();
public:
	Span(const Span& other);
	Span(unsigned int n);
	
	Span& operator=(const Span& other);
	~Span();

	void	sortArr();
	
	int		shortestSpan();
	int		longestSpan();
	
	void	addNumber(int n);

	template	<typename T>
	void	addNumber(T first, T last)
	{
		if (static_cast<unsigned int>(std::distance(first, last)) > N - arr.size())
			throw std::range_error("Impossible to add, no space available!");
		arr.insert(arr.end(), first, last);
		_sorted = false;
	}
};

#endif