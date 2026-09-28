#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("noName_clap_name", 100, 50, 30) , name("noName")
{
	std::cout << RED << "DIAMONDTRAP DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& otherName)
	: ClapTrap(otherName + "_clap_name", 100, 50, 30) , name(otherName)
{
	std::cout << GREEN << "DIAMONDTRAP CONSTRUCTOR WITH NAME CALLED!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other.ClapTrap::name, other.hitPoints, other.energyPoints, other.attackDamage),
	ScavTrap(), FragTrap(), name(other.name)
{
	std::cout << GREEN << "DIAMONDTRAP COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << GREEN << "DIAMONDTRAP COPY ASSIGNMENT OPERATOR CALLED!" << RESET << std::endl;

	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	ClapTrap::name = other.ClapTrap::name;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DIAMONDTRAP DESTRUCTOR CALLED!" << RESET << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << name << ", but also " << ClapTrap::name << "!" << std::endl;
}