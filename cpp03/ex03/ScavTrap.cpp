#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("noName", 100, 50, 20)
{
	std::cout << RED << "SCAVTRAP DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string &otherName) : ClapTrap(otherName, 100, 50, 20)
{
	std::cout << GREEN << "SCAVTRAP CONSTRUCTOR WITH NAME CALLED!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other.name, other.hitPoints, other.energyPoints, other.attackDamage)
{
	std::cout << GREEN << "SCAVTRAP COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << GREEN << "SCAVTRAP COPY ASSIGNMENT OPERATOR CALLED!" << RESET << std::endl;

	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "SCAVTRAP DESTRUCTOR CALLED!" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is dead!" << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " had no energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}