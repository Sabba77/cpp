#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN << "CAT DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << GREEN << "CAT COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << GREEN << "CAT COPY ASSIGNMENT OPERATOR CALLED!" << RESET << std::endl;

	if (this == &other)
		return *this;
	Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << GREEN << "CAT DESTRUCTOR CALLED!" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << GREEN << "MIAAAAO!!!" << RESET << std::endl;
}