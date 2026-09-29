#include "AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "CURE DEFAULT CONSTRUCTOR CALLED!" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "CURE COPY CONSTRUCTOR CALLED!" << std::endl;
}

Cure& Cure::operator=(const Cure&)
{
	std::cout << "CURE COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;
	return *this;
}

Cure::~Cure()
{
	std::cout << "CURE DESTRUCTOR CALLED!" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria* clone = new Cure(*this);
	return clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<  "'s wounds *" << std::endl;
}