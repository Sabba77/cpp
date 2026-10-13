#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << GREEN << "DOG DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl;
	dogBrain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << GREEN << "DOG COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
	dogBrain = new Brain(*other.dogBrain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << GREEN << "DOG COPY ASSIGNMENT OPERATOR CALLED!" << RESET << std::endl;

	if (this == &other)
		return *this;
	Animal::operator=(other);
	*dogBrain = *other.dogBrain;
	return *this;
}

Dog::~Dog()
{
	delete dogBrain;
	std::cout << GREEN << "DOG DESTRUCTOR CALLED!" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF!!!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return dogBrain;
}