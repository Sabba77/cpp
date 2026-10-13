#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << GREEN << "DOG DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << GREEN << "DOG COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << GREEN << "DOG COPY ASSIGNMENT OPERATOR CALLED!" << RESET << std::endl;

	if (this == &other)
		return *this;
	Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << GREEN << "DOG DESTRUCTOR CALLED!" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << GREEN << "WOOF!!!" << RESET << std::endl;
}