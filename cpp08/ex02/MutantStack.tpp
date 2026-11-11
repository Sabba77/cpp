#include "MutantStack.hpp"
#include <iostream>

template	<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << BLACK_GRAY << "DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

template	<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
	std::cout << BLACK_GRAY << "COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}

template	<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	std::cout << BLACK_GRAY << "COPY ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template	<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << BLACK_GRAY << "DESTRUCTOR CALLED" << RESET << std::endl;
}
