#include "AMateria.hpp"

AMateria::AMateria() : type("noType")
{
	std::cout << "DEFAULT CONSTRUCTOR CALLED!" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "DESTRUCTOR CALLED!" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.getType())
{
	std::cout << "COPY CONSTRUCTOR CALLED!" << std::endl;
}

AMateria::AMateria(const std::string& type) : type(type)
{
	std::cout << "CONSTRUCTOR WITH TYPE CALLED!" << std::endl;
}

AMateria& AMateria::operator=(const AMateria&)
{
	std::cout << "COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;
	return *this;
}

std::string const& AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Generic materia used over " << target.getName()  << "." << std::endl;
}