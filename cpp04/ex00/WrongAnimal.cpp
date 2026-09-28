#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WRONG DEFAULT CONSTRUCTOR CALLED!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WRONG COPY CONSTRUCTOR CALLED!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &otherType) : type(otherType)
{
	std::cout << "WRONG DEFAULT CONSTRUCTOR WITH NAME CALLED!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WRONG COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;

	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WRONG DESTRUCTOR CALLED!" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Some random WrongAnimal sounds..." << std::endl;
}