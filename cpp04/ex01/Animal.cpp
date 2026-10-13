#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << GREEN << "DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << GREEN << "COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
}

Animal::Animal(const std::string &otherType) : type(otherType)
{
	std::cout << GREEN << "DEFAULT CONSTRUCTOR WITH NAME CALLED!" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << GREEN << "COPY ASSIGNMENT OPERATOR CALLED!" << RESET << std::endl;

	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << GREEN << "DESTRUCTOR CALLED!" << RESET << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << GREEN << "Some random animal sounds..." << RESET << std::endl;
}