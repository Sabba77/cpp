#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WRONGCAT DEFAULT CONSTRUCTOR CALLED!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WRONGCAT COPY CONSTRUCTOR CALLED!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WRONGCAT COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;

	if (this == &other)
		return *this;
	WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WRONGCAT DESTRUCTOR CALLED!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WRONG MIAAAAO!!!" << std::endl;
}