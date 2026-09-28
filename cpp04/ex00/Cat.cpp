#include "Animal.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "CAT DEFAULT CONSTRUCTOR CALLED!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "CAT COPY CONSTRUCTOR CALLED!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "CAT COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;

	if (this == &other)
		return *this;
	Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << "CAT DESTRUCTOR CALLED!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MIAAAAO!!!" << std::endl;
}