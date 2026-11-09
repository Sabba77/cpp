#include <iostream>
#include <stdexcept>
#include <cstddef>

template	<typename T>
Array<T>::Array() : num(0), arr(NULL)
{
	std::cout << BLACK_GRAY << "DEFAULT TEMPLATE CONSTRUCTOR CALLED" << RESET << std::endl;
}

template	<typename T>
Array<T>::Array(unsigned int n) : num(n), arr(new T[n]())
{
	std::cout << BLACK_GRAY << "PARAMETRIC TEMPLATE CONSTRUCTOR CALLED" << RESET << std::endl;
}

template	<typename T>
Array<T>::Array(const Array<T>& other) : num(other.num), arr(new T[other.num]())
{
	std::cout << BLACK_GRAY << "COPY TEMPLATE CONSTRUCTOR CALLED" << RESET << std::endl;
	for (unsigned int i = 0; i < num; i++)
		arr[i] = other.arr[i];
}

template	<typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	std::cout << BLACK_GRAY << "COPY TEMPLATE ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;
	if (this != &other)
	{
		T* tmp = new T[other.num]();          // 1. alloco in locale: se fallisce, *this è intatto
		for (unsigned int i = 0; i < other.num; i++)
			tmp[i] = other.arr[i];            // 2. copio in tmp
		delete[] arr;                         // 3. libero il vecchio buffer
		arr = tmp;                            // 4. aggiorno puntatore e dimensione
		num = other.num;
	}
	return *this;
}

template	<typename T>
T&	Array<T>::operator[](unsigned int n)
{
	if (n >= num)
		throw std::out_of_range("Array index out of range");
	return arr[n];
}

template	<typename T>
const T& Array<T>::operator[](unsigned int n) const
{
	if (n >= num)
		throw std::out_of_range("Array index out of range");
	return arr[n];
}

template	<typename T>
Array<T>::~Array()
{
	delete[] arr;
	std::cout << BLACK_GRAY << "DESTRUCTOR TEMPLATE CALLED" << RESET << std::endl;
}

template	<typename T>
unsigned int	Array<T>::size() const
{
	return num;
}
