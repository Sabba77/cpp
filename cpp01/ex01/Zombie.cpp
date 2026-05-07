#include "Zombie.hpp"

# include <iostream>

Zombie::Zombie() : _name("(unnamed)") {
	// Quando crei un horde con new Zombie[N], ogni elemento parte da qui.
}

Zombie::Zombie(std::string const &name) : _name(name) {
}

Zombie::~Zombie() {
	// Il testo esatto non è imposto, ma deve contenere il nome.
	std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void Zombie::setName(std::string const &name) {
	_name = name;
}

void Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
