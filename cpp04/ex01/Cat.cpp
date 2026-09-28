#include "Animal.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "CAT DEFAULT CONSTRUCTOR CALLED!" << std::endl;
	catBrain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "CAT COPY CONSTRUCTOR CALLED!" << std::endl;
	catBrain = new Brain(*other.catBrain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "CAT COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;

	if (this == &other)
		return *this;
	Animal::operator=(other);
	*catBrain = *other.catBrain;
	return *this;
}

Cat::~Cat()
{
	delete catBrain;
	std::cout << "CAT DESTRUCTOR CALLED!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MIAAAAAO!!!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return catBrain;
}