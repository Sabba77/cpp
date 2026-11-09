#ifndef ARRAY_HPP
# define ARRAY_HPP

#define RED			"\033[31m"
#define STRIKE_RED	"\033[9;31m"
#define GREEN		"\033[32m"
#define YELLOW		"\x1b[33m"
#define BOLD_CYAN	"\033[1;36m"
#define BLACK_GRAY	"\033[90m"
#define RESET		"\033[0m"

template	<typename T>
class	Array
{
private:
	unsigned int	num;
	T* arr;

public:
	Array();
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	Array(unsigned int n);

	T& operator[](unsigned int n);
	const T& operator[](unsigned int n) const;
	unsigned int	size(void) const;
};

#include "Array.tpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#endif