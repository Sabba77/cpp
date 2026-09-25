#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("noName") , hitPoints(10) , energyPoints(10) , attackDamage(0)
{
	std::cout << RED << "DEFAULT CONSTRUCTOR CALLED!" << RESET  << std::endl;
}

ClapTrap::ClapTrap(const std::string &otherName) : name(otherName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << GREEN << "CONSTRUCTOR WITH NAME CALLED!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << GREEN << "COPY CONSTRUCTOR CALLED!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& otherName, unsigned int hP, unsigned int eP, unsigned int aD)
	: name(otherName) , hitPoints(hP) , energyPoints(eP) , attackDamage(aD) 
{
	std::cout << GREEN << "CONSTRUCTOR WITH ALL ATTRIBUTES CALLED!" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << GREEN << "COPY ASSIGNMENT OPERATOR CALLED!" << RESET << std::endl;

	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "DESTRUCTOR CALLED!" << RESET << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " had no energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " received " << ((hitPoints >= amount) ? amount : hitPoints) << " damage points!" << std::endl;
	(hitPoints >= amount) ? hitPoints = hitPoints - amount : hitPoints = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " had no energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " is healing by " << amount << " hit points..." << std::endl;
	hitPoints = hitPoints + amount;
	energyPoints--;
}

std::string	ClapTrap::getName(void) const
{
	return name;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return attackDamage;
}