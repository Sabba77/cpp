#include "Animal.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "DOG DEFAULT CONSTRUCTOR CALLED!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "DOG COPY CONSTRUCTOR CALLED!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "DOG COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;

	if (this == &other)
		return *this;
	Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "DOG DESTRUCTOR CALLED!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF!!!" << std::endl;
}