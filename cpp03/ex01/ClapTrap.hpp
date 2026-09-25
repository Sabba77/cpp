#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

class	ClapTrap
{
protected:
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap(const std::string& otherName);
	ClapTrap(const std::string& otherName, unsigned int hP, unsigned int eP, unsigned int aD);

	ClapTrap& operator=(const ClapTrap& other);

	~ClapTrap();

	std::string		getName(void) const;
	unsigned int	getAttackDamage(void) const;

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif