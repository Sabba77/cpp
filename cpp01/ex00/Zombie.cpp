#include "Zombie.hpp"

Zombie::Zombie() : _name("(unnamed)")
{}

Zombie::Zombie(std::string const& name) : _name(name)
{}

Zombie::~Zombie()
{
	std::cout << RED << "Zombie " << _name << " destroyed" << RESET << std::endl;
}

void Zombie::setName(std::string const& name)
{
	_name = name;
}

void Zombie::announce(void) const
{
	std::cout << GREEN << _name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
