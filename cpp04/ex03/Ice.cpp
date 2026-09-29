#include "AMateria.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "ICE DEFAULT CONSTRUCTOR CALLED!" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "ICE COPY CONSTRUCTOR CALLED!" << std::endl;
}

Ice& Ice::operator=(const Ice&)
{
	std::cout << "ICE COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;
	return *this;
}

Ice::~Ice()
{
	std::cout << "ICE DESTRUCTOR CALLED!" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria* clone = new Ice(*this);
	return clone;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()  << " *"<< std::endl;
}
