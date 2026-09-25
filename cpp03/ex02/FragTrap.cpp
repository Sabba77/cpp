#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("noName", 100, 100, 30)
{
	std::cout << RED << "FRAGTRAP DEFAULT CONSTRUCTOR CALLED!" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string &otherName) : ClapTrap(otherName, 100, 100, 30)
{
	std::cout << GREEN << "FRAGTRAP CONSTRUCTOR WITH NAME CALLED!" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other.name, other.hitPoints, other.energyPoints, other.attackDamage)
{
	std::cout << GREEN << "FRAGTRAP COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << GREEN << "FRAGTRAP COPY ASSIGNMENT OPERATOR CALLED!" << RESET << std::endl;

	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FRAGTRAP DESTRUCTOR CALLED!" << RESET << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is dead!" << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << "FragTrap " << name << " had no energy!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " says HIGH FIVE GUYS!" << std::endl;
}