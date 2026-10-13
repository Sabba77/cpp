#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN << "CAT DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl;
	catBrain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << GREEN << "CAT COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
	catBrain = new Brain(*other.catBrain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << GREEN << "CAT COPY ASSIGNMENT OPERATOR CALLED!" << RESET << std::endl;

	if (this == &other)
		return *this;
	Animal::operator=(other);
	*catBrain = *other.catBrain;
	return *this;
}

Cat::~Cat()
{
	delete catBrain;
	std::cout << GREEN << "CAT DESTRUCTOR CALLED!" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MIAAAAAO!!!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return catBrain;
}