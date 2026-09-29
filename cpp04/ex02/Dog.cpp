#include "Animal.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "DOG DEFAULT CONSTRUCTOR CALLED!" << std::endl;
	dogBrain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "DOG COPY CONSTRUCTOR CALLED!" << std::endl;
	dogBrain = new Brain(*other.dogBrain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "DOG COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;

	if (this == &other)
		return *this;
	Animal::operator=(other);
	*dogBrain = *other.dogBrain;
	return *this;
}

Dog::~Dog()
{
	delete dogBrain;
	std::cout << "DOG DESTRUCTOR CALLED!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF!!!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return dogBrain;
}