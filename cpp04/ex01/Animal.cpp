#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "DEFAULT CONSTRUCTOR CALLED!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "COPY CONSTRUCTOR CALLED!" << std::endl;
}

Animal::Animal(const std::string &otherType) : type(otherType)
{
	std::cout << "DEFAULT CONSTRUCTOR WITH NAME CALLED!" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;

	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "DESTRUCTOR CALLED!" << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Some random animal sounds..." << std::endl;
}