#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap(const std::string& otherName);

	FragTrap& operator=(const FragTrap& other);

	~FragTrap();

	
	void	attack(const std::string& target);
	void	highFivesGuys(void);
};

#endif